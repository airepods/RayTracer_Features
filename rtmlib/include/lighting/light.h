#ifndef LIGHT_H    
#define LIGHT_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/vector_utility.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/color.h"
#include "pointLight.h"
#include "materials/material.h"
#include "worldScene/world.h"
#include "computations/computation.h"

namespace rtm
{
    // Because the l vector is pointing out towards the surface
    inline Vector reflect(const Vector& l, const Vector& normal) { return -l + 2*dot(l, normal)*normal; }

    Color lighting(const Material& material, const PointLight& light, const Point& point, const Vector& eyev, const Vector& normalv);
    Color shade_hit(const World& world, const Computation& comps);
}

#endif