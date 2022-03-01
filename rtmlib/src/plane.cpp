#include "primitives/plane.h"
#include "mat_constants/math_constants.h"

#include <vector>

#include <iostream>

using namespace rtm;

Plane::Plane() : Surface()
{}

std::vector<Intersection> Plane::local_intersect(const Ray& ray) const
{
    if(std::abs(ray.direction().y()) < rtm::constants::epsilon)
    {
        std::vector<Intersection> e;
        return e;
    }

    double t = -ray.origin().y()/ray.direction().y();

    std::vector<Intersection> intersections = {Intersection(t, this)};

    return intersections;
}

std::vector<Intersection> Plane::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    return local_intersect(ray);
}


Vector Plane::normal_at(const Point& world_point) const
{
    // Getting the normal vector in object space
    auto object_normal = Vector(0, 1, 0);
    // Taking the normal vector in object space and pass it to world space
    auto world_normal = (inverse(m_transform)).transpose() * object_normal;
    // Set the w component to 0 because I am considering the translation component
    // of the transformation matrix and because of that, the w might change. 
    world_normal.set_w(0);

    return normalize(world_normal);
}