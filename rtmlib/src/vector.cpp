#include "mat_entities/vector.h"
#include "util/utils.h"
#include <cmath>
#include <string>

using namespace std;
using namespace rtm;

Vector::Vector()
{}

Vector::Vector(float x, float y, float z) : Tuple(x, y, z)
{
    t[3] = 0.0f;
}

Vector::Vector(float x, float y, float z, float w) : Tuple(x, y, z, w)
{}

Vector::Vector(float* elements) : Tuple(elements)
{}

string Vector::to_str()
{
    string out = "";

    for(int i=0; i<4; ++i)
    {
        out += ftos(t[i], 3) + " ";
    }

    return out;
}

Vector Vector::operator-()
{
    return Vector(-t[0], -t[1], -t[2]);
}

float Vector::magnitude()
{
    return sqrt(t[0]*t[0] + t[1]*t[1] + t[2]*t[2] + t[3]*t[3]);
}

Vector Vector::normalize()
{
    return Vector(t[0]/this->magnitude(), 
                  t[1]/this->magnitude(), 
                  t[2]/this->magnitude());
}

float Vector::dot(Vector v)
{
    return t[0]*v.x() + 
           t[1]*v.y() +
           t[2]*v.z() +
           t[3]*v.w();
}