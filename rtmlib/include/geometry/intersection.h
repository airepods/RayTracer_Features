#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "intersections.h"
#include "primitives/surface.h"
#include <string>

namespace rtm
{
class Intersection : public Intersections
{
    private:
        float t;
        Surface* object;
    public:
        Intersection();

        Intersection(float t_val , Surface* object_val);

        float get_t() override;
        Surface* get_shape() override; 

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const;
};
} //namespace rtm

#endif