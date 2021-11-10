#ifndef RAY_INTERSECTION_H    
#define RAY_INTERSECTION_H   

#include <vector>
#include "intersection.h"
#include "ray.h"
#include "mat_entities/point.h"

namespace rtm
{
bool hit(std::vector<Intersection*>& record, Intersection& intersection_ouput);
bool hit(std::vector<Intersection>& record, Intersection& intersection_ouput);
bool hit(std::vector<Intersection>& record);
Point position(const Ray&, float);
} // namespace rtm

#endif