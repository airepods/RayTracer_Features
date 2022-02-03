#ifndef PREPARE_COMPUTATIONS_H    
#define PREPARE_COMPUTATIONS_H

#include "computation.h"
#include "geometry/ray_intersection.h"

#include <vector>
#include <list>
#include <algorithm>

namespace rtm
{
    Computation prepare_computations(const Intersection& i, const Ray& r, std::vector<Intersection> xs = {}); 
    
} //namespace rtm

#endif