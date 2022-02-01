#ifndef RAY_INTERSECTION_H    
#define RAY_INTERSECTION_H   

#include <vector>
#include "intersection.h" // intersections contains ray

namespace rtm
{
bool hit(std::vector<Intersection*>& record, Intersection& intersection_ouput);
bool hit(std::vector<Intersection>& record, Intersection& intersection_ouput);
bool hit(std::vector<Intersection>& record);
Point position(const Ray&, const double&);
} // namespace rtm

#endif