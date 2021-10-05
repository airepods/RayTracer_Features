#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "primitives/sphere.h"

template <class T>
class Intersection
{
    private:
        float _t;
        T _object;
    public:
        Intersection()
        {}
        Intersection(float t , T object) : _t(t), _object(object) 
        {}

        float get_t_value()
        {
            return _t;
        }

        T get_objectType()
        {
            return _object;
        }

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const
        {
        return (_t < i._t);
        }

};

#endif