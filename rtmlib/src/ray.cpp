#include "geometry/ray.h"
#include "mat_entities/matrix_utility.h"

using namespace rtm;

Ray::Ray()
{}

Ray::Ray(const Point& origin, const Vector& direction) : _origin(origin), _direction(direction)
{}

Ray Ray::transform(const Matrix& m) const
{
    Ray transformed_ray(m * this->origin(), m * this->direction());
    return transformed_ray;
}