#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "geometry/intersection.h"
#include "primitives/shape.h"
#include <vector>
#include <string>

class Sphere : public Shape
{
    public:
        Sphere();
        std::vector<Intersection> intersects(Ray r);
        
        inline std::string type_to_str() override {return "Sphere";}
        inline Sphere* get_object_type() override {return this;}
};


#endif