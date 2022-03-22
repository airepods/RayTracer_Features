#include "primitives/smoothTriangle.h"

//#include <iostream>

#include "mat_constants/math_constants.h"
#include <cmath>

using namespace rtm;

SmoothTriangle::SmoothTriangle() : Surface()
{}

SmoothTriangle::SmoothTriangle(
    const Point& p1, 
    const Point& p2, 
    const Point& p3, 
    const Vector& n1, 
    const Vector& n2, 
    const Vector& n3)
    : Surface()
{
    // vertices
    m_p1 = p1;
    m_p2 = p2;
    m_p3 = p3;
    // normal vertices
    m_n1 = n1;
    m_n2 = n2;
    m_n3 = n3;
    // edges
    m_e1 = p2 - p1;
    m_e2 = p3 - p1;
    // face normal
    m_normal = normalize(cross(m_e2, m_e1));
}

SmoothTriangle::SmoothTriangle(const SmoothTriangle& s) : Surface(s)
{
    m_p1 = s.m_p1;
    m_p2 = s.m_p2;
    m_p3 = s.m_p3;
    m_n1 = s.m_n1;
    m_n2 = s.m_n2;
    m_n3 = s.m_n3;
    m_e1 = s.m_e1;
    m_e2 = s.m_e2;
    m_normal = s.m_normal;
}

SmoothTriangle& SmoothTriangle::operator= (const SmoothTriangle& s)
{
    // Triangle class attribbutes
    m_p1 = s.m_p1;
    m_p2 = s.m_p2;
    m_p3 = s.m_p3;
    m_n1 = s.m_n1;
    m_n2 = s.m_n2;
    m_n3 = s.m_n3;
    m_e1 = s.m_e1;
    m_e2 = s.m_e2;
    m_normal = s.m_normal;

    // Surface base class attributes
    Surface::operator=(s);
    return *this;
}

SmoothTriangle::~SmoothTriangle()
{
    //std::cout<<"Triangle destructor"<<"\n";
}

std::vector<Intersection> SmoothTriangle::local_intersect(const Ray& ray) const
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

    intersections.push_back(Intersection(t, this, u, v));
    return intersections;
}

std::vector<Intersection> SmoothTriangle::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inv_transform);

    return local_intersect(ray);
}

Vector SmoothTriangle::normal_at(const Point& world_point, const Intersection& hit) const
{
    // Getting the normal vector in object space (local normal)
    Vector object_normal = m_n2 * hit.u +
                           m_n3 * hit.v +
                           m_n1 * (1 - hit.u - hit.v);

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = normal_to_world(object_normal);
     
    return world_normal;
}

void SmoothTriangle::set_invTransform()
{
    inv_transform = inverse(m_transform);
}