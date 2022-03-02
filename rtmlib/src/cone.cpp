#include "primitives/cone.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <limits> // for infinity

#include <iostream>

#include "mat_constants/math_constants.h"

using namespace rtm;

Cone::Cone() : Surface()
{
    m_minimum = -std::numeric_limits<double>::infinity();
    m_maximum =  std::numeric_limits<double>::infinity();
    m_closed = false;
}

Cone::Cone(double minimum, double maximum, bool closed) : Surface()
{
    m_minimum = minimum;
    m_maximum = maximum;
    m_closed = closed;
}


std::vector<Intersection> Cone::local_intersect(const Ray& ray) const
{
    std::vector<Intersection> intersections = {};

    double a = std::pow(ray.direction().x(), 2) - std::pow(ray.direction().y(), 2) + std::pow(ray.direction().z(), 2);
    double b = 2 * ray.direction().x() * ray.origin().x() -
               2 * ray.direction().y() * ray.origin().y() +
               2 * ray.direction().z() * ray.origin().z();
    double c = std::pow(ray.origin().x(), 2) - std::pow(ray.origin().y(), 2) + std::pow(ray.origin().z(), 2);

    if(a == 0 && b == 0) {return intersections;}

    // ray parallel to one of cone's halves (single intersection in the middle)
    if(a == 0 && b != 0) 
    {
        double t = -c/(2*b);
        intersections.push_back(Intersection(t, this));
        intersect_caps(ray, intersections);
        return intersections;
    } 

    double discriminant = std::pow(b, 2) - 4 * a * c;  
    // if ray does not intersect the cone 
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

std::vector<Intersection> Cone::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    return local_intersect(ray);
}

Vector Cone::normal_at(const Point& world_point) const
{
    // Passing the point in world space to object space
    auto object_point = world_to_object(world_point);

    // Getting the normal vector in object space (local normal)
    Vector object_normal;
    double dist = std::pow(object_point.x(), 2) + std::pow(object_point.z(), 2);
    if(dist < 1 && object_point.y() >= m_maximum - rtm::constants::epsilon)
    {
        object_normal = Vector(0, 1, 0);
    }
    else
    {
        if(dist < 1 && object_point.y() <= m_minimum + rtm::constants::epsilon)
        {
            object_normal = Vector(0, -1, 0);
        }
        else
        {
            double y = std::sqrt(std::pow(object_point.x(), 2) + std::pow(object_point.z(), 2));
            if (object_point.y() > 0) { y *= -1; }

            object_normal = Vector(object_point.x(), y, object_point.z());
        }
    }

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = normal_to_world(object_normal);
     
    return world_normal;
}

void Cone::intersect_caps(const Ray& r, std::vector<Intersection>& xs) const
{
    // if the cone is not closed or the direction in y is close to zero
    if(m_closed == false || std::abs(r.direction().y()) <= rtm::constants::epsilon)
        return;
    
    double t;
    // check for an intersection with the lower end cap y = minimum
    t = (m_minimum - r.origin().y()) / r.direction().y();
    if(check_cap(r, t, m_minimum))
        xs.push_back(Intersection(t, this));
    
    // check for an intersection with the upper end cap y = maximum
    t = (m_maximum - r.origin().y()) / r.direction().y();
    if(check_cap(r, t, m_maximum))
        xs.push_back(Intersection(t, this));
}

// accept the y coordinate of the plane being tested (the radius is not always 1)
// the cone has a variable radius as it extends to the infinite (up or down)
// y_cap -> the y coordinate of the cone's cap (minimum or maximum)
bool Cone::check_cap(const Ray& r, const double& t, const double& y_cap) const
{
    double x = r.origin().x() + t * r.direction().x();
    double z = r.origin().z() + t * r.direction().z();

    return (std::pow(x, 2) + std::pow(z, 2)) <= std::abs(y_cap); // a cone’s radius at any given y will be the absolute value of that y.
}