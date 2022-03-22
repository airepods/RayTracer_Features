#include "primitives/cylinder.h"

//#include <iostream>

#include <cmath>
#include <vector>
#include <algorithm>
#include <limits> // for infinity

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

Cylinder::Cylinder(const Cylinder& s) : Surface(s)
{
    m_minimum = s.m_minimum;
    m_maximum = s.m_maximum;
    m_closed = s.m_closed;
}

Cylinder& Cylinder::operator= (const Cylinder& s)
{
    // Cylinder class attribbutes
    m_minimum = s.m_minimum;
    m_maximum = s.m_maximum;
    m_closed = s.m_closed;

    // Surface base class attributes
    Surface::operator=(s);
    return *this;
}

Cylinder::~Cylinder()
{
    //std::cout<<"Cylinder destructor"<<"\n";
}

std::vector<Intersection> Cylinder::local_intersect(const Ray& ray) const
{
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

std::vector<Intersection> Cylinder::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    return local_intersect(ray);
}

Vector Cylinder::normal_at(const Point& world_point, const Intersection& hit) const
{
    auto w_point = world_point;
    // Passing the point in world space to object space
    auto object_point = world_to_object(w_point);

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
            object_normal = Vector(object_point.x(), 0, object_point.z());
        }
    }

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = normal_to_world(object_normal);
     
    return world_normal;
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