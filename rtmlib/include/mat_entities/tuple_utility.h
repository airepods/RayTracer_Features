#ifndef TUPLE_UTILITY_H    
#define TUPLE_UTILITY_H

#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"

namespace rtm
{
// tuple basic operations functions
// Addition
Vector operator+(Vector, Vector);
Point operator+(Vector, Point);
Point operator+(Point, Vector);
Color operator+(Color, Color);

// Substraction
Vector operator-(Vector, Vector);
Point operator-(Vector, Point);
Point operator-(Point, Vector);
Vector operator-(Point, Point);
Color operator-(Color, Color);

// Multiplication by scalar
template<class T>
T operator*(T t, float scalar)
{
    return T(t.x()*scalar, t.y()*scalar, t.z()*scalar);
}

template<class T>
T operator*(float scalar, T t)
{
    return t*scalar;
}

// Division by scalar
template<class T>
T operator/(T t, float scalar)
{
    return T(t.x()/scalar, t.y()/scalar, t.z()/scalar);
}
}
#endif