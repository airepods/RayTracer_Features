#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "intersections.h"
#include "primitives/shape.h"
#include <string>

namespace rtm
{
class Intersection : public Intersections
{
    private:
        float t;
        Shape* object = nullptr;
    public:
        Intersection();

        Intersection(float t_val , Shape* object_val);

        float get_t() override;
        Shape* get_shape() override; 

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const;
};
} //namespace rtm

#endif