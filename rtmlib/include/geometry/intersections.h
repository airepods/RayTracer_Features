#ifndef INTERSECTIONS_H    
#define INTERSECTIONS_H

#include <string>
#include "primitives/shape.h"

// Abstract base class 

namespace rtm
{
class Intersections
{
public:
    virtual float get_t() = 0;
    virtual Shape* get_shape() = 0;
};
} //namespace rtm

#endif