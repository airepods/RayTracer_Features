#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "primitives/surface.h"
#include "geometry/intersection.h"
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
        std::vector<Intersection> intersects_with(const Ray&) const override;
        Vector normal_at(const Point& world_point) const override;
        
        //inline Sphere* get_object_type() override {return this;}
        inline std::string type_to_str() const override {return "Sphere";}
};
} //namespace rtm

#endif