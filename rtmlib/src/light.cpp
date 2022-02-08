#include "lighting/light.h"

using namespace rtm;

Color rtm::lighting(const Material& material, const Surface* object, const PointLight& light, const Point& point, const Vector& eyev, const Vector& normalv, const bool& in_shadow)
{
    // check for patterns
    // if material has pattern
    rtm::Color color;
    if(material.get_pattern() != nullptr)
        color = material.get_pattern()->pattern_at_object(object, point);
    else
        color = material.get_color();

    Color effective_color = color * light.get_intensity();
    
    // find the direction to the light source
    Vector lightv = normalize(light.get_position() - point);

    // compute the ambient contribution
    Color ambient = effective_color * material.get_ambient();
    Color diffuse;
    Color specular;

    auto light_dot_normal = dot(lightv, normalv);
    if(light_dot_normal < 0 || in_shadow)
    {
        diffuse = Color(0, 0, 0);
        specular = Color(0, 0, 0);
    }
    else
    {
        diffuse = effective_color * material.get_diffuse() * light_dot_normal;
        
        // compute the reflection vector
        auto reflectv = reflect(lightv, normalv);
        auto reflect_dot_eye = dot(reflectv, eyev);

        if(reflect_dot_eye <= 0)
        {
            specular = Color(0, 0, 0);
        }
        else
        {
            double factor = std::pow(reflect_dot_eye, material.get_shininess());
            specular = light.get_intensity() * material.get_specular() * factor;
        }
    }

    return ambient + diffuse + specular;
}

Color rtm::shade_hit(const World& world, const Computation& comps, int& remaining)
{
    auto shadow = is_shadowed(world, comps.over_point);
    auto surface = lighting(comps.surface->get_material(), 
                            comps.surface, 
                            world.get_pointLight(), 
                            comps.over_point, comps.eyev, comps.normalv, 
                            shadow);

    auto reflected = reflected_color(world, comps, remaining);
    auto refracted = refracted_color(world, comps, remaining);

    auto material = comps.surface->get_material();
    // if material is reflective and also glassy (transparent -> enables refraction of light)
    if(material.get_reflective() > 0 && material.get_transparency() > 0)
    {
        auto reflectance = fresnel_schlick(comps);
        return (surface + reflected) * reflectance + refracted * (1 - reflectance);
    }

    return surface + reflected + refracted;
}

Color rtm::color_at(const World& world, const Ray& ray, int remaining)
{
    auto xs = world.intersects_with(ray);
    auto color = Color();

    auto intersection = rtm::Intersection(); 
    if(hit(xs, intersection))
    {
        auto comps = prepare_computations(intersection, ray, xs);
        color = rtm::shade_hit(world, comps, remaining);
    }
    else
    {
        color = rtm::Color(0, 0, 0);
    }

    return color;
}

bool rtm::is_shadowed(const World& world, const Point& point)
{
    auto v = world.get_pointLight().get_position() - point;
    auto distance = v.magnitude();
    auto direction = normalize(v);

    auto ray = Ray(point, direction);
    auto intersections = world.intersects_with(ray);
    Intersection intersection_output;

    if(hit(intersections, intersection_output))
    {
        if(distance > intersection_output.get_t())
            return true;
    }

    return false;
}

Color rtm::reflected_color(const World& world, const Computation& comps, int& remaining)
{
    if(comps.surface->get_material().get_reflective() == 0 || remaining <= 0) // if the remaining value is 0 or less, finish the recursion tree
        return rtm::Color(0, 0, 0);
    
    auto reflect_ray = Ray(comps.over_point, comps.reflectv);
    remaining-=1; // decrease by 1 the remaining value, so the recursion can stop
    auto color = color_at(world, reflect_ray, remaining);

    return color * comps.surface->get_material().get_reflective();
}

Color rtm::refracted_color(const World& world, const Computation& comps, int& remaining)
{
    // max recursion depth
    if(remaining == 0)
        return rtm::Color(0, 0, 0);

    double n_ratio = comps.n1 / comps.n2;
    // for theta i (incident ray)
    double cos_i =  dot(comps.eyev, comps.normalv);
    // find sin^2(theta)
    double sin2_t = std::pow(n_ratio, 2) * (1 - std::pow(cos_i, 2));

    // if sin(theta) is grater than 1 (greater then 90 degrees angle), then we are in total internal reflection
    if(comps.surface->get_material().get_transparency() == 0 || sin2_t > 1) 
        return rtm::Color(0, 0, 0);
    
    double cos_t = std::sqrt(1.0 - sin2_t);
    // -comps.eye because the ray direction is inverted in prepare_computations
    auto direction = n_ratio*(-comps.eyev) + comps.normalv * (n_ratio * cos_i - cos_t); // direction of refracted ray
    // refracted ray
    auto refracted_ray = Ray(comps.under_point, direction);
    // compute the color
    auto color = color_at(world, refracted_ray, remaining - 1) * comps.surface->get_material().get_transparency();

    return color;
}

double rtm::fresnel_schlick(const Computation& comps)
{
    double cos = dot(comps.eyev, comps.normalv);

    // total internal reflection only occurs when n1>n2 
    // angle = arcsin(n2/n1) iff n1 > n2 (because arcsin needs to be between the range 0-1)
    if(comps.n1 > comps.n2)
    {
        double n_ratio = comps.n1 / comps.n2;
        double sin2_t = std::pow(n_ratio, 2) * (1 - std::pow(cos, 2));
        if (sin2_t > 1.0) return 1.0; // Total Internal Reflection (TIR)
        // compute cos of theta t
        double cos_t = std::sqrt(1.0 - sin2_t);
        // when n1 > n2 use cos_t instead
        cos = cos_t;
    } 

    double r0 = (comps.n1 - comps.n2) / (comps.n1 + comps.n2);
    r0 *= r0;
    double x = 1.0 - cos;
    return r0 + (1.0 - r0) * std::pow(x, 5);
}




