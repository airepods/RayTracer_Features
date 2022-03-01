#include "primitives/sphere.h"

#include <cmath>
#include <vector>

#include <iostream>

using namespace rtm;

Sphere::Sphere() : Surface()
{}

std::vector<Intersection> Sphere::local_intersect(const Ray& ray) const
{
    Vector sphere_to_ray = ray.origin() - Point(0, 0, 0);

    double a = dot(ray.direction(), ray.direction());
    double b = 2 * dot(ray.direction(), sphere_to_ray);
    double c = dot(sphere_to_ray, sphere_to_ray) - 1;

    double discriminant = std::pow(b, 2) - 4 * a * c;

    if(discriminant < 0)
    {
        std::vector<Intersection> e;
        return e;
    }

    double t1 = (-b - std::sqrt(discriminant)) / (2 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2 * a);

    std::vector<Intersection> intersections = {Intersection(t1, this), Intersection(t2, this)};

    return intersections;
}

std::vector<Intersection> Sphere::intersects_with(const Ray& r) const
{
    // Here I am transforming the ray
    // Transform the ray by the inverse of the sphere's transformation matrix 
    Ray ray2 = r.transform(inverse(this->get_transform()));
    
    return local_intersect(ray2);
}

Vector Sphere::normal_at(const Point& world_point) const
{
    // Passing the point in world space to object space
    auto object_point = inverse(m_transform) * world_point;
    // Getting the normal vector in object space
    auto object_normal = object_point - rtm::Point(0, 0, 0);
    // Taking the normal vector in object space and pass it to world space
    auto world_normal = (inverse(m_transform)).transpose() * object_normal;
    // Set the w component to 0 because I am considering the translation component
    // of the transformation matrix and because of that, the w might change. 
    world_normal.set_w(0);

    return normalize(world_normal);
}