#include "primitives/sphere.h"
#include "mat_entities/vector.h"
#include "mat_entities/matrix.h"
#include "mat_entities/matrix_utility.h"
#include <cmath>
#include <vector>
#include "geometry/intersection.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/vector_utility.h"

#include <iostream>

using namespace rtm;

Sphere::Sphere() : _transform{Matrix(4, 4)}
{
    _transform.set_identity();
}

void Sphere::transform(const Matrix& transformation)
{
    _transform = transformation;
}

std::vector<Intersection> Sphere::intersects(const Ray& r)
{
    // Here I am transforming the ray
    // Transform the ray by the inverse of the sphere's transformation matrix 
    Ray ray2 = r.transform(inverse(this->get_transform()));
    
    Vector sphere_to_ray = ray2.origin() - Point(0, 0, 0);

    float a = dot(ray2.direction(), ray2.direction());
    float b = 2 * dot(ray2.direction(), sphere_to_ray);
    float c = dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = pow(b, 2) - 4 * a * c;

    if(discriminant < 0)
    {
        std::vector<Intersection> e;
        return e;
    }

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    std::vector<Intersection> intersections = {Intersection(t1, this), Intersection(t2, this)};

    return intersections;
}