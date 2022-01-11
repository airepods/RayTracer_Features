#ifndef TUPLE_UTILITY_H    
#define TUPLE_UTILITY_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"

namespace rtm
{
// tuple basic operations functions
// Addition
Vector operator+(const Vector&, const Vector&);
Point operator+(const Vector&, const Point&);
Point operator+(const Point&, const Vector&);
Color operator+(const Color&, const Color&);

// Substraction
Vector operator-(const Vector&, const Vector&);
Point operator-(const Vector&, const Point&);
Point operator-(const Point&, const Vector&);
Vector operator-(const Point&, const Point&);
Color operator-(const Color&, const Color&);

// Multiplication by scalar
template<class T>
T operator*(const T& t, const double& scalar)
{
    return T(t.x()*scalar, t.y()*scalar, t.z()*scalar);
}

template<class T>
T operator*(double scalar, const T& t)
{
    return t*scalar;
}

// Division by scalar
template<class T>
T operator/(const T& t, const double& scalar)
{
    return T(t.x()/scalar, t.y()/scalar, t.z()/scalar);
}
}
#endif