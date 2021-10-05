#ifndef RAY_H    
#define RAY_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"

class Ray
{
    private:
        Point _origin;
        Vector _direction;
    public:
        Ray();
        Ray(Point origin, Vector direction);

        Point origin();
        Vector direction();     
};

Point position(Ray, float);

#endif