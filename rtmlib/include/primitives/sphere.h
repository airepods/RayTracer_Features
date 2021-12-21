#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "geometry/intersection.h"
#include "primitives/surface.h"
#include "mat_entities/matrix.h"
#include <vector>
#include <string>
#include "materials/material.h"

namespace rtm
{
class Sphere : public Surface
{
    public:
        Sphere();

        std::vector<Intersection> intersects(const Ray&);
        inline Sphere* get_object_type() {return this;}

        inline std::string type_to_str() override {return "Sphere";}
        Vector normal_at(const Point& world_point) override;
};
} //namespace rtm

#endif