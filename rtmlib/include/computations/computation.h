#ifndef COMPUTATION_H    
#define COMPUTATION_H

#include "primitives/surface.h"
#include "mat_entities/point.h"
#include "mat_entities/vector.h"

namespace rtm
{
struct Computation
{
    double tvalue;
    Surface* surface;
    Point point;
    Vector eyev;
    Vector normalv;
    Point over_point; // for acne effect - point moved slighly in the direction of normal 
    bool inside;
};
} // namespace rtm

#endif