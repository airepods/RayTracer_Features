#ifndef RAY_INTERSECTION_H    
#define RAY_INTERSECTION_H   

#include <vector>
#include "intersection.h"
#include "ray.h"
#include "mat_entities/point.h"

namespace rtm
{
bool hit(std::vector<Intersection*> record, Intersection& intersection_ouput);
Point position(Ray, float);
} // namespace rtm

#endif