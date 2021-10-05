#include "geometry/geo_test.h"
#include "primitives/sphere.h"
#include "geometry/ray.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "geometry/intersection.h"
#include "util/utils.h"
#include <cmath>
#include <algorithm>
#include <vector>


Intersection<Sphere>* intersect(Sphere s, Ray r)
{
    Vector sphere_to_ray = r.origin() - Point(0, 0, 0);

    float a = dot(r.direction(), r.direction());
    float b = 2 * dot(r.direction(), sphere_to_ray);
    float c = dot(sphere_to_ray, sphere_to_ray) - 1;

    float discriminant = pow(b, 2) - 4 * a * c;

    if(discriminant < 0)
        return nullptr;

    Intersection<Sphere>* intersections = new Intersection<Sphere>[2]; 

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    intersections[0] = Intersection<Sphere>(t1, s);
    intersections[1] = Intersection<Sphere>(t2, s);

    return intersections;
}

Intersection<Sphere>* hit(vector<Intersection<Sphere>> record)
{
    std::sort(record.begin(), record.end());

    for (auto i : record)
    {
        if(i.get_t_value() >= 0)
        {
            return new Intersection<Sphere>(i.get_t_value(), i.get_objectType());
        }
    }

    return nullptr;
}