#include "primitives/cylinder.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <limits> // for infinity

#include <iostream>

#include "mat_constants/math_constants.h"

using namespace rtm;

Cylinder::Cylinder() : Surface()
{
    m_minimum = -std::numeric_limits<double>::infinity();
    m_maximum =  std::numeric_limits<double>::infinity();
    m_closed = false;
}

Cylinder::Cylinder(double minimum, double maximum, bool closed) : Surface()
{
    m_minimum = minimum;
    m_maximum = maximum;
    m_closed = closed;
}

std::vector<Intersection> Cylinder::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    std::vector<Intersection> intersections = {};

    // same logic as ray-sphere intersection but 
    // this time only consider x and z axis
    double a = std::pow(ray.direction().x(), 2) + std::pow(ray.direction().z(), 2);
    // ray is parallel to the y axis
    if(std::abs(a) <= rtm::constants::epsilon)
    {   
        intersect_caps(ray, intersections);
        return intersections;
    }

    double b = 2 * ray.direction().x() * ray.origin().x() +
               2 * ray.direction().z() * ray.origin().z();
    double c = std::pow(ray.origin().x(), 2) + std::pow(ray.origin().z(), 2) - 1; // radius of the cylinder = 1 and center = (0, 0, 0)

    double discriminant = std::pow(b, 2) - 4 * a * c;

    // ray does not intersect the cylinder 
    if (discriminant < 0)
    {
        return intersections;
    }

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    if (t1 > t2) std::swap(t1, t2);

    double y1 = ray.origin().y() + t1 * ray.direction().y();
    if(m_minimum < y1 && y1 < m_maximum)
        intersections.push_back(Intersection(t1, this));

    double y2 = ray.origin().y() + t2 * ray.direction().y();
    if(m_minimum < y2 && y2 < m_maximum)
        intersections.push_back(Intersection(t2, this));

    // caps
    intersect_caps(ray, intersections);

    return intersections;
}

Vector Cylinder::normal_at(const Point& world_point) const
{
    // Passing the point in world space to object space
    auto object_point = inverse(m_transform) * world_point;

    // Getting the normal vector in object space (local normal)
    auto object_normal = Vector(object_point.x(), 0, object_point.z());

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = (inverse(m_transform)).transpose() * object_normal;
    // Set the w component to 0 because I am considering the translation component
    // of the transformation matrix and because of that, the w might change. 
    world_normal.set_w(0);

    return normalize(world_normal);
}

void Cylinder::intersect_caps(const Ray& r, std::vector<Intersection>& xs) const
{
    // if the cylinder is not closed or the direction in y is close to zero
    if(m_closed == false || std::abs(r.direction().y()) <= rtm::constants::epsilon)
        return;
    
    double t;
    // check for an intersection with the lower end cap y = minimum
    t = (m_minimum - r.origin().y()) / r.direction().y();
    if(check_cap(r, t))
        xs.push_back(Intersection(t, this));
    
    // check for an intersection with the upper end cap y = maximum
    t = (m_maximum - r.origin().y()) / r.direction().y();
    if(check_cap(r, t))
        xs.push_back(Intersection(t, this));
}

bool Cylinder::check_cap(const Ray& r, const double& t) const
{
    double x = r.origin().x() + t * r.direction().x();
    double z = r.origin().z() + t * r.direction().z();

    return (x*x + z*z) <= 1;
}