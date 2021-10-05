#ifndef TUPLE_H    
#define TUPLE_H

#include "util/utils.h"
#include <string>

class Vector;
class Point;
class Color;

class Tuple
{
    protected:
        float t[4];
        int c[3];

    public:
        Tuple();
        Tuple(float x, float y, float z);
        Tuple(float x, float y, float z, float w);
        Tuple(float* elements);

        virtual std::string to_str() = 0;

        template<class T>
        bool is_equal_to(T tuple)
        {
            for(int i=0; i<4; ++i)
            {
                if(!fcompare(t[i], tuple.t[i]))
                    return false;
            }
            return true;
        }
};

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

#endif