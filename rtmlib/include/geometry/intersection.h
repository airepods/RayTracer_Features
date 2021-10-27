#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "intersections.h"
#include "primitives/shape.h"
#include <vector>
#include <algorithm>
#include <string>

class Intersection : public Intersections
{
    private:
        float t;
        Shape* object;
    public:
        Intersection()
        {}
        Intersection(float t_val , Shape* object_val) : t(t_val), object(object_val) 
        {}

        float get_t() override {return t;}
        inline Shape* get_shape() override {return object;}

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

    for (auto&& current_intersection : record)
    {
        if(current_intersection.get_t() >= 0)
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

    for (auto&& current_intersection : record)
    {
        if(current_intersection.get_t() >= 0)
        {
            intersection_ouput = current_intersection;
            return true;
        }
    }

    return false;
}

#endif