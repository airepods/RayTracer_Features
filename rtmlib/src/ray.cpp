#include "geometry/ray.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"

Ray::Ray()
{}

Ray::Ray(Point origin, Vector direction) : _origin(origin), _direction(direction)
{}

Point Ray::origin()
{
    return _origin;
}

Vector Ray::direction()
{
    return _direction;
}

Point position(Ray r, float t)
{
    return r.origin() + r.direction()*t;
}