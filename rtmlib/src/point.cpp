#include "mat_entities/point.h"
#include "util/utils.h"
#include <string>

using namespace std;
using namespace rtm;

Point::Point()
{}

Point::Point(float x, float y, float z) : Tuple(x, y, z)
{
    t[3] = 1.0f;
}

Point::Point(float x, float y, float z, float w) : Tuple(x, y, z, w)
{}


Point::Point(float* elements) : Tuple(elements)
{}

string Point::to_str()
{
    string out = "";

    for(int i=0; i<4; ++i)
    {
        out += ftos(t[i], 3) + " ";
    }

    return out;
}

Point Point::operator- ()
{
    return Point(-t[0], -t[1], -t[2], -t[3]);
}