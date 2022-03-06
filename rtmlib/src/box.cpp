#include "primitives/box.h"

#include "mat_constants/math_constants.h"

#include <vector>
#include <algorithm>
#include <cmath>

//#include <iostream>

using namespace rtm;

Box::Box() : Surface()
{}

Box::~Box()
{
    //std::cout<<"Box destructor"<<"\n";
}

std::vector<Intersection> Box::local_intersect(const Ray& ray) const
{
    double txmin = (-1 - ray.origin().x()) / ray.direction().x();
    double txmax = ( 1 - ray.origin().x()) / ray.direction().x();

    if (txmin > txmax) std::swap(txmin, txmax);

    double tymin = (-1 - ray.origin().y()) / ray.direction().y();
    double tymax = ( 1 - ray.origin().y()) / ray.direction().y();

    if (tymin > tymax) std::swap(tymin, tymax);

    double tzmin = (-1 - ray.origin().z()) / ray.direction().z();
    double tzmax = ( 1 - ray.origin().z()) / ray.direction().z();

    if (tzmin > tzmax) std::swap(tzmin, tzmax);

    double tmin = std::max({txmin, tymin, tzmin});
    double tmax = std::min({txmax, tymax, tzmax});

    if(tmin > tmax)
    {
        std::vector<Intersection> e;
        return e;
    }

    std::vector<Intersection> intersections = {Intersection(tmin, this), Intersection(tmax, this)};
    return intersections;
}

std::vector<Intersection> Box::intersects_with(const Ray& r) const
{
    Ray ray = r.transform(inverse(this->get_transform()));
    
    return local_intersect(ray);
}

Vector Box::normal_at(const Point& world_point) const
{
    auto w_point = world_point;
    // Passing the point in world space to object space
    auto object_point = world_to_object(w_point);
    
    // Getting the normal vector in object space (local normal)
    double maxc = std::max({std::abs(object_point.x()), std::abs(object_point.y()), std::abs(object_point.z())});
    Vector object_normal;
    if( fcompare(maxc, std::abs(object_point.x())) ) 
    {
        object_normal = Vector(object_point.x(), 0, 0);
    }
    else 
    {
        if( fcompare(maxc, std::abs(object_point.y())) )
            object_normal = Vector(0, object_point.y(), 0);
        else
            object_normal = Vector(0, 0, object_point.z());
    }

    // Taking the normal vector in object space and pass it to world space
    auto world_normal = normal_to_world(object_normal);
    return world_normal;
}