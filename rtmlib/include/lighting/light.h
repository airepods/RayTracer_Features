#ifndef LIGHT_H    
#define LIGHT_H

#include <mat_entities/vector.h>
#include <mat_entities/point.h>
#include <mat_entities/vector_utility.h>
#include <mat_entities/tuple_utility.h>
#include <mat_entities/color.h>
#include <lighting/pointLight.h>
#include <materials/material.h>

namespace rtm
{
    // Because the l vector is pointing out towards the surface
    inline Vector reflect(Vector l, Vector normal) { return -l + 2*dot(l, normal)*normal; }

    Color lighting(Material material, PointLight light, Point point, Vector eyev, Vector normalv);
}

#endif