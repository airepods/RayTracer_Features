#include "mat_entities/tuple.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"

using namespace rtm;

Tuple::Tuple()
{}

Tuple::Tuple(const double& x, const double& y, const double& z)
{
    t[0] = x;
    t[1] = y;
    t[2] = z;
}

Tuple::Tuple(const double& x, const double& y, const double& z, const double& w)
{
    t[0] = x;
    t[1] = y;
    t[2] = z;
    t[3] = w;
}

Tuple::Tuple(double* elements)
{
    t[0] = elements[0];
    t[1] = elements[1];
    t[2] = elements[2];
    t[3] = elements[3];
}



