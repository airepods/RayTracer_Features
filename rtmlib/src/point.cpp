#include "mat_entities/point.h"
#include <string>

using namespace std;
using namespace rtm;

// Default constructor
Point::Point()
{}

// Custom constructor
Point::Point(const double& x, const double& y, const double& z) : Tuple(x, y, z)
{
    t[3] = 1.0;
}

// Another custom constructor, takes an additional w parameter
Point::Point(const double& x, const double& y, const double& z, const double& w) : Tuple(x, y, z, w)
{}

// Constructs a point from an array of elements (primitive array)
Point::Point(double* elements) : Tuple(elements)
{}

// Return a string with the values of a point
string Point::to_str() const
{
    string out = "";

    for(int i=0; i<4; ++i)
    {
        out += dtos(t[i], 3) + " ";
    }

    return out;
}

// Negate a point
Point Point::operator- () const
{
    return Point(-t[0], -t[1], -t[2], -t[3]);
}