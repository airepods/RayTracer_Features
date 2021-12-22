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
        float m_t;
        Surface* m_object;
    public:
        Intersection();

        Intersection(const float& t_val , const Surface* object_val);

        float get_t() const override;
        Surface* get_shape() const override; 

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const;
};
} //namespace rtm

#endif