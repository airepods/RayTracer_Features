#ifndef SPHERE_H    
#define SPHERE_H

#include "geometry/ray.h" 
#include "geometry/intersection.h"
#include "primitives/sphere.h"
#include <vector>
#include <string>

class Sphere
{
    public:
        Sphere();
        std::vector<Intersection<Sphere>> intersects(Ray r);
        inline std::string type_to_str() {return "Sphere";}
};


#endif