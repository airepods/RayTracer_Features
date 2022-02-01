#include "geometry/ray.h"

using namespace rtm;

Ray::Ray()
{}

Ray::Ray(const Point& origin, const Vector& direction) : m_origin(origin), m_direction(direction)
{}

Ray Ray::transform(const Matrix& m) const
{
    Ray transformed_ray(m * this->origin(), m * this->direction());
    return transformed_ray;
}