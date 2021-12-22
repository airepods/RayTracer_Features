#ifndef PREPARE_COMPUTATIONS_H    
#define PREPARE_COMPUTATIONS_H

#include "computation.h"
#include "geometry/intersection.h"
#include "geometry/ray.h"

namespace rtm
{
    Computation prepare_computations(const Intersection& i, const Ray& r); 
    
} //namespace rtm

#endif