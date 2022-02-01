#ifndef LIGHT_H    
#define LIGHT_H

#include "worldScene/world.h"
#include "computations/prepare_computations.h"

namespace rtm
{
    // Because the l vector is pointing out towards the surface
    inline Vector reflect(const Vector& l, const Vector& normal) { return -l + 2*dot(l, normal)*normal; }

    Color lighting(const Material& material, const Surface* object, const PointLight& light, const Point& point, const Vector& eyev, const Vector& normalv, const bool& in_shadow = false);
    Color shade_hit(const World& world, const Computation& comps);
    Color color_at(const World& world, const Ray& ray);
    bool is_shadowed(const World& world, const Point& point);
}

#endif