#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "primitives/sphere.h"
#include <vector>
#include <algorithm>

class no_hit {};

template <class T>
class Intersection
{
    public:
        float t;
        T object;

        Intersection()
        {}
        Intersection(float t_val , T object_val) : t(t_val), object(object_val) 
        {}

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const
        {
        return (t < i.t);
        }
};

template <class T>
bool hit(std::vector<T> record)
{
    std::sort(record.begin(), record.end());

    for (auto i : record)
    {
        if(i.t >= 0)
        {
            return true;
        }
    }

    return false;
}

template <class T>
bool hit(std::vector<T> record, T& intersection_ouput)
{
    std::sort(record.begin(), record.end());

    for (auto current_intersection : record)
    {
        if(current_intersection.t >= 0)
        {
            intersection_ouput = current_intersection;
            return true;
        }
    }

    return false;
}

#endif