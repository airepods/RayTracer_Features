#ifndef RAY_H    
#define RAY_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"

namespace rtm
{
class Ray
{
    private:
        Point _origin;
        Vector _direction;
    public:
        Ray();
        Ray(const Point& origin, const Vector& direction);

        inline Point origin() const {return _origin;}
        inline Vector direction() const {return _direction;}     
};
} //namespace rtm

#endif