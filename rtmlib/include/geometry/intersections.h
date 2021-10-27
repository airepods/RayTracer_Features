#ifndef INTERSECTIONS_H    
#define INTERSECTIONS_H

#include <string>

class Intersections
{
public:
    virtual float get_t() = 0;
    virtual Intersections* get_object_type() = 0;
};

#endif