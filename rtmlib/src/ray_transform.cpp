#include "geometry/ray_transform.h"
#include "geometry/ray.h"
#include "mat_entities/matrix_utility.h"

using namespace rtm;

Ray rtm::transform(const Ray& r, const Matrix& m)
{
    Ray transformed_ray(m * r.origin(), m * r.direction());
    return transformed_ray;
}