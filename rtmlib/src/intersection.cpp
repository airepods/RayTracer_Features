#include "geometry/intersection.h"

Intersection::Intersection()
{}

Intersection::Intersection(float t_val , Shape* object_val) : t(t_val), object(object_val) 
{}

float Intersection::get_t()
{
    return t;
}

Shape* Intersection::get_shape()
{
    return object;
}

bool Intersection::operator < (const Intersection& i) const
{
    return (t < i.t);
}

bool hit(std::vector<Intersection*> record, Intersection& intersection_ouput)
{
    std::sort(record.begin(), record.end(), [](Intersection* a, Intersection* b){return *a < *b;});

    for (auto&& current_intersection : record)
    {
        if(current_intersection->get_t() >= 0)
        {
            intersection_ouput = *current_intersection;
            return true;
        }
    }

    return false;
}
