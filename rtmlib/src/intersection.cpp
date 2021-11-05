#include "geometry/intersection.h"

using namespace rtm;

Intersection::Intersection() : object(nullptr)
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

