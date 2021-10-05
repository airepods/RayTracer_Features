#include "mat_entities/tuple.h"
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"

Tuple::Tuple()
{}

Tuple::Tuple(float x, float y, float z)
{
    t[0] = x;
    t[1] = y;
    t[2] = z;
}

Tuple::Tuple(float x, float y, float z, float w)
{
    t[0] = x;
    t[1] = y;
    t[2] = z;
    t[3] = w;
}

Tuple::Tuple(float* elements)
{
    t[0] = elements[0];
    t[1] = elements[1];
    t[2] = elements[2];
    t[3] = elements[3];
}

// Defining basic operations functions
//Addition
Vector operator+(Vector vec1, Vector vec2)
{
    return Vector(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
}

Point operator+(Vector vec1, Point p1)
{
    return Point(vec1.x() + p1.x(), vec1.y() + p1.y(), vec1.z() + p1.z());
}

Point operator+(Point p1, Vector vec1)
{
    return vec1+p1;
}

Color operator+(Color c1, Color c2)
{
    return Color(c1.red() + c2.red(), c1.green() + c2.green(), c1.blue() + c2.blue());
}

//Substraction
Vector operator-(Vector vec1, Vector vec2)
{
    return Vector(vec1.x() - vec2.x(), vec1.y() - vec2.y(), vec1.z() - vec2.z());
}

Point operator-(Vector vec1, Point p1)
{
    return Point(vec1.x() - p1.x(), vec1.y() - p1.y(), vec1.z() - p1.z());
}

Point operator-(Point p1, Vector vec1)
{
    return Point(p1.x() - vec1.x(), p1.y() - vec1.y(), p1.z() - vec1.z());
}

Vector operator-(Point p1, Point p2)
{
    return Vector(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
}

Color operator-(Color c1, Color c2)
{
    return Color(c1.red() - c2.red(), c1.green() - c2.green(), c1.blue() - c2.blue());
}


