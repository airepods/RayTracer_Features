#include "mat_entities/tuple_utility.h"

using namespace rtm;

// Defining basic operations functions
//Addition
Vector rtm::operator+(Vector vec1, Vector vec2)
{
    return Vector(vec1.x() + vec2.x(), vec1.y() + vec2.y(), vec1.z() + vec2.z());
}

Point rtm::operator+(Vector vec1, Point p1)
{
    return Point(vec1.x() + p1.x(), vec1.y() + p1.y(), vec1.z() + p1.z());
}

Point rtm::operator+(Point p1, Vector vec1)
{
    return vec1+p1;
}

Color rtm::operator+(Color c1, Color c2)
{
    return Color(c1.red() + c2.red(), c1.green() + c2.green(), c1.blue() + c2.blue());
}

//Substraction
Vector rtm::operator-(Vector vec1, Vector vec2)
{
    return Vector(vec1.x() - vec2.x(), vec1.y() - vec2.y(), vec1.z() - vec2.z());
}

Point rtm::operator-(Vector vec1, Point p1)
{
    return Point(vec1.x() - p1.x(), vec1.y() - p1.y(), vec1.z() - p1.z());
}

Point rtm::operator-(Point p1, Vector vec1)
{
    return Point(p1.x() - vec1.x(), p1.y() - vec1.y(), p1.z() - vec1.z());
}

Vector rtm::operator-(Point p1, Point p2)
{
    return Vector(p1.x() - p2.x(), p1.y() - p2.y(), p1.z() - p2.z());
}

Color rtm::operator-(Color c1, Color c2)
{
    return Color(c1.red() - c2.red(), c1.green() - c2.green(), c1.blue() - c2.blue());
}