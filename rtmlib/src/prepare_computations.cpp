#include "computations/prepare_computations.h"
#include "geometry/ray_intersection.h"
#include "mat_entities/vector_utility.h"

using namespace rtm;

Computation rtm::prepare_computations(const Intersection& i, const Ray& ray)
{
    // instantiate a data structure for storing some precomputed values
    Computation comps;

    // copy the intersection's properties
    comps.tvalue = i.get_t();
    comps.surface = i.get_shape();

    // precompute some useful values
    comps.point = position(ray, comps.tvalue);
    comps.eyev = -ray.direction();
    comps.normalv = comps.surface->normal_at(comps.point);

    if(dot(comps.normalv, comps.eyev) < 0)
    {
        comps.inside = true;
        comps.normalv = -comps.normalv;
    }
    else
    {
        comps.inside = false;
    }

    return comps;
}