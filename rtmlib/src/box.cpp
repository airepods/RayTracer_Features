#include "primitives/box.h"

#include <vector>
#include <algorithm>

using namespace rtm;

Box::Box() : Surface()
{}

std::vector<Intersection> Box::intersects_with(const Ray& ray) const
{
    // Basic cases
    // TODO handle cases when direction is 0

    double txmin = (-1 - ray.origin().x()) / ray.direction().x();
    double txmax = ( 1 - ray.origin().x()) / ray.direction().x();

    double tymin = (-1 - ray.origin().y()) / ray.direction().y();
    double tymax = ( 1 - ray.origin().y()) / ray.direction().y();

    double tzmin = (-1 - ray.origin().z()) / ray.direction().z();
    double tzmax = ( 1 - ray.origin().z()) / ray.direction().z();

    double tmin = std::max(txmin, tymin, tzmin);
    double tmax = std::min(txmax, tymax, tzmax);

    std::vector<Intersection> intersections = {Intersection(tmin, this), Intersection(tmax, this)};
    return intersections;
}

Vector Box::normal_at(const Point& world_point) const
{
    return Vector(1, 1, 1);
}