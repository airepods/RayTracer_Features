#include "lighting/light.h"

#include <cmath>

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
    auto surface = lighting(comps.surface->get_material(), comps.surface, world.get_pointLight(), comps.over_point, comps.eyev, comps.normalv, shadow);
    auto reflected = reflected_color(world, comps, remaining);

    return surface + reflected;
}

Color rtm::color_at(const World& world, const Ray& ray, int remaining)
{
    auto xs = world.intersects_with(ray);
    auto color = Color();

    auto intersection = rtm::Intersection(); 
    if(hit(xs, intersection))
    {
        auto comps = prepare_computations(intersection, ray);
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
    if(comps.surface->get_material().get_reflective() == 0.0f || remaining <= 0) // if the remaining value is 0 or less, finish the recursion tree
        return rtm::Color(0, 0, 0);
    
    auto reflect_ray = Ray(comps.over_point, comps.reflectv);
    remaining-=1; // decrease by 1 the remaining value, so the recursion can stop
    auto color = color_at(world, reflect_ray, remaining);

    return color * comps.surface->get_material().get_reflective();
}


