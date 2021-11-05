#include "mat_entities/point.h"
#include "util/utils.h"
#include <string>

using namespace std;
using namespace rtm;

// Default constructor
Point::Point()
{}

// Custom constructor
Point::Point(float x, float y, float z) : Tuple(x, y, z)
{
    t[3] = 1.0f;
}

// Another custom constructor, takes an additional w parameter
Point::Point(float x, float y, float z, float w) : Tuple(x, y, z, w)
{}

// Constructs a point from an array of elements (primitive array)
Point::Point(float* elements) : Tuple(elements)
{}

// Return a string with the values of a point
string Point::to_str()
{
    string out = "";

    for(int i=0; i<4; ++i)
    {
        out += ftos(t[i], 3) + " ";
    }

    return out;
}

// Negate a point
Point Point::operator- ()
{
    return Point(-t[0], -t[1], -t[2], -t[3]);
}