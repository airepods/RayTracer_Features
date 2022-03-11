#include "primitives/triangle.h"

//#include <iostream>

#include "mat_constants/math_constants.h"
#include <cmath>

using namespace rtm;

Triangle::Triangle() : Surface()
{}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) : Surface()
{
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
    m_e1 = p2 - p1;
    m_e2 = p3 - p1;
    m_normal = normalize(cross(m_e2, m_e1));
}

Triangle::Triangle(const Triangle& s) : Surface(s)
{
    m_p1 = s.m_p1;
    m_p2 = s.m_p2;
    m_p3 = s.m_p3;
    m_e1 = s.m_e1;
    m_e2 = s.m_e2;
    m_normal = s.m_normal;
}

Triangle& Triangle::operator= (const Triangle& s)
{
    // Triangle class attribbutes
    m_p1 = s.m_p1;
    m_p2 = s.m_p2;
    m_p3 = s.m_p3;
    m_e1 = s.m_e1;
    m_e2 = s.m_e2;
    m_normal = s.m_normal;

    // Surface base class attributes
    Surface::operator=(s);
    return *this;
}

Triangle::~Triangle()
{
    //std::cout<<"Triangle destructor"<<"\n";
}

std::vector<Intersection> Triangle::local_intersect(const Ray& ray) const
{
    std::vector<Intersection> intersections = {};

    // needs to determine t, u and v components

    // first compute the determinant
    auto dir_cross_e2 = cross(ray.direction(), m_e2);
    auto det = dot(dir_cross_e2, m_e1);

    // if the determinant is nearly zero, there is no intersection
    if(std::abs(det) < rtm::constants::epsilon) {return intersections;}

    auto inv_det = 1.0/det;

    // compute the U component
    // T = O - Vo
    auto p1_to_origin = ray.origin() - m_p1;
    auto u = inv_det * dot(dir_cross_e2, p1_to_origin);
    // if u is not between the range 0, 1 (inclusive) then there is
    // no intersection (u and v are barycentric coordinates)
    if(u < 0 || u > 1) {return intersections;}

    // compute the V component
    auto origin_cross_e1 = cross(p1_to_origin, m_e1);
    auto v = inv_det * dot(origin_cross_e1, ray.direction());
    if(v < 0 || (u + v) > 1) {return intersections;}

    // computes the T component
    auto t = inv_det * dot(origin_cross_e1, m_e2);

    intersections.push_back(Intersection(t, this));
    return intersections;
}

std::vector<Intersection> Triangle::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));

    return local_intersect(ray);
}

Vector Triangle::normal_at(const Point& world_point) const
{
    // Getting the normal vector in object space (local normal)
    Vector object_normal = m_normal;

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = normal_to_world(object_normal);
     
    return world_normal;
}