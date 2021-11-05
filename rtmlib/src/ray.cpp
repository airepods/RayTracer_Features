#include "geometry/ray.h"

using namespace rtm;

Ray::Ray()
{}

Ray::Ray(const Point& origin, const Vector& direction) : _origin(origin), _direction(direction)
{}