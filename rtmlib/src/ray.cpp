#include "geometry/ray.h"

using namespace rtm;

Ray::Ray()
{}

Ray::Ray(Point origin, Vector direction) : _origin(origin), _direction(direction)
{}

Point Ray::origin() const
{
    return _origin;
}

Vector Ray::direction() const
{
    return _direction;
}