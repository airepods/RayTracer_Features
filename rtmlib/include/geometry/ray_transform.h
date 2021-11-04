#ifndef RAY_TRANSFORM_H    
#define RAY_TRANSFORM_H 

#include "ray.h"
#include "mat_entities/matrix.h"

namespace rtm
{
Ray transform(const Ray& r, const Matrix& m);
} // namespace rtm

#endif