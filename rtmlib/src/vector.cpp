#include "mat_entities/vector.h"
#include "util/utils.h"
#include <cmath>
#include <string>

using namespace std;
using namespace rtm;

// Default constructor
Vector::Vector()
{}

// Custom constructor
Vector::Vector(const double& x, const double& y, const double& z) : Tuple(x, y, z)
{
    t[3] = 0.0;
}

Vector::Vector(const double& x, const double& y, const double& z, const double& w) : Tuple(x, y, z, w)
{}

// Construct a vector from an primitive array
Vector::Vector(double* elements) : Tuple(elements)
{}

// Return a string of the values of a vector
string Vector::to_str() const
{
    string out = "";

    for(int i=0; i<4; ++i)
    {
        out += dtos(t[i], 3) + " ";
    }

    return out;
}

// Negate a vector
Vector Vector::operator-() const
{
    return Vector(-t[0], -t[1], -t[2]);
}

// Compute the magnitude/norm of a vector
double Vector::magnitude() const
{
    return sqrt(t[0]*t[0] + t[1]*t[1] + t[2]*t[2] + t[3]*t[3]);
}

// Normalize a vector
Vector Vector::normalize() const
{
    return Vector(t[0]/this->magnitude(), 
                  t[1]/this->magnitude(), 
                  t[2]/this->magnitude());
}

// Compute the dot product of a vector
double Vector::dot(const Vector& v) const
{
    return t[0]*v.x() + 
           t[1]*v.y() +
           t[2]*v.z() +
           t[3]*v.w();
}