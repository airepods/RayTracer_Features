#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "primitives/surface.h"
#include <string>

namespace rtm
{
class Intersection
{
    private:
        double m_t;
        Surface* m_object;
    public:
        Intersection();

        Intersection(const double& t_val , const Surface* object_val);

        double get_t() const;
        Surface* get_shape() const; 

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const;
};
} //namespace rtm

#endif