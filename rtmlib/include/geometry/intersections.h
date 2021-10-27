#ifndef INTERSECTIONS_H    
#define INTERSECTIONS_H

#include <string>
#include "primitives/shape.h"

class Intersections
{
public:
    virtual float get_t() = 0;
    virtual Shape* get_shape() = 0;
};

#endif