#include "primitives/cylinder.h"

#include <cmath>
#include <vector>

#include <iostream>

using namespace rtm;

Cylinder::Cylinder() : Surface()
{}

std::vector<Intersection> Cylinder::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    // same logic as ray-sphere intersection but 
    // this time only consider x and z axis
    double a = std::pow(ray.direction().x(), 2) + std::pow(ray.direction().z(), 2);
    double b = 2 * ray.direction().x() * ray.origin().x() +
               2 * ray.direction().z() * ray.origin().z();
    double c = std::pow(ray.origin().x(), 2) + std::pow(ray.origin().z(), 2) - 1; // radius of the cylinder = 1 and center = (0, 0, 0)

    double discriminant = std::pow(b, 2) - 4 * a * c;

    // ray does not intersect the cylinder 
    if (discriminant < 0)
    {
        std::vector<Intersection> e;
        return e;
    }

    std::vector<Intersection> intersections = {Intersection(1, this)};

    return intersections;
}

Vector Cylinder::normal_at(const Point& world_point) const
{
    // Passing the point in world space to object space
    auto object_point = inverse(m_transform) * world_point;

    // Getting the normal vector in object space (local normal)
    auto object_normal = object_point - rtm::Point(0, 0, 0);

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = (inverse(m_transform)).transpose() * object_normal;
    // Set the w component to 0 because I am considering the translation component
    // of the transformation matrix and because of that, the w might change. 
    world_normal.set_w(0);

    return normalize(world_normal);
}