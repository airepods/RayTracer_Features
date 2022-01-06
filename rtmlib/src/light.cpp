#include "lighting/light.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/vector_utility.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/color.h"
#include "lighting/pointLight.h"
#include "materials/material.h"
#include "geometry/intersection.h"
#include "geometry/ray_intersection.h"
#include "computations/prepare_computations.h"
#include <cmath>

using namespace rtm;

Color rtm::lighting(const Material& material, const PointLight& light, const Point& point, const Vector& eyev, const Vector& normalv, const bool& in_shadow)
{
    Color effective_color = material.get_color() * light.get_intensity();
    
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
            float factor = pow(reflect_dot_eye, material.get_shininess());
            specular = light.get_intensity() * material.get_specular() * factor;
        }
    }

    return ambient + diffuse + specular;
}

Color rtm::shade_hit(const World& world, const Computation& comps)
{
    auto shadow = is_shadowed(world, comps.over_point);
    return lighting(comps.surface->get_material(), world.get_pointLight(), comps.over_point, comps.eyev, comps.normalv, shadow);
}

Color rtm::color_at(const World& world, const Ray& ray)
{
    auto xs = world.intersects_with(ray);
    auto color = Color();

    auto intersection = rtm::Intersection(); 
    if(hit(xs, intersection))
    {
        auto comps = prepare_computations(intersection, ray);
        color = rtm::shade_hit(world, comps);
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


