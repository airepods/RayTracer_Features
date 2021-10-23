#include "primitives/sphere.h"
#include "geometry/ray.h"
#include "mat_entities/vector.h"
#include <cmath>
#include <vector>
#include "geometry/intersection.h"

Sphere::Sphere()
{}

std::vector<Intersection<Sphere>> Sphere::intersects(Ray r)
{
    Vector sphere_to_ray = r.origin() - Point(0, 0, 0);

    float a = dot(r.direction(), r.direction());
    float b = 2 * dot(r.direction(), sphere_to_ray);
    float c = dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = pow(b, 2) - 4 * a * c;

    if(discriminant < 0)
    {
        std::vector<Intersection<Sphere>> e;
        return e;
    }

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    std::vector<Intersection<Sphere>> intersections = {Intersection<Sphere>(t1, *this), Intersection<Sphere>(t2, *this)};

    return intersections;
}