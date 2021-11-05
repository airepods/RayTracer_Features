#include "mat_entities/tuple_utility.h"

using namespace rtm;

// Defining basic operations functions
//Addition
Vector rtm::operator+(const Vector& vec1, const Vector& vec2)
{
    return Vector(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
}

Point rtm::operator+(const Vector& vec1, const Point& p1)
{
    return Point(vec1.x() + p1.x(), vec1.y() + p1.y(), vec1.z() + p1.z());
}

Point rtm::operator+(const Point& p1, const Vector& vec1)
{
    return vec1+p1;
}

Color rtm::operator+(const Color& c1, const Color& c2)
{
    return Color(c1.red() + c2.red(), c1.green() + c2.green(), c1.blue() + c2.blue());
}

//Substraction
Vector rtm::operator-(const Vector& vec1, const Vector& vec2)
{
    return Vector(vec1.x() - vec2.x(), vec1.y() - vec2.y(), vec1.z() - vec2.z());
}

Point rtm::operator-(const Vector& vec1, const Point& p1)
{
    return Point(vec1.x() - p1.x(), vec1.y() - p1.y(), vec1.z() - p1.z());
}

Point rtm::operator-(const Point& p1, const Vector& vec1)
{
    return Point(p1.x() - vec1.x(), p1.y() - vec1.y(), p1.z() - vec1.z());
}

Vector rtm::operator-(const Point& p1, const Point& p2)
{
    return Vector(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
}

Color rtm::operator-(const Color& c1, const Color& c2)
{
    return Color(c1.red() - c2.red(), c1.green() - c2.green(), c1.blue() - c2.blue());
}