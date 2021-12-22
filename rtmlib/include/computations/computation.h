#ifndef COMPUTATION_H    
#define COMPUTATION_H

#include "primitives/surface.h"
#include "mat_entities/point.h"
#include "mat_entities/vector.h"

namespace rtm
{
struct Computation
{
    float tvalue;
    Surface* surface;
    Point point;
    Vector eyev;
    Vector normalv;
    bool inside;
};
} // namespace rtm

#endif