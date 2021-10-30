#ifndef VECTOR_H    
#define VECTOR_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Vector : public Tuple
{
    public:
        Vector();
        Vector(float x, float y, float z);
        Vector(float x, float y, float z, float w);
        Vector(float* elements);

        inline float x() const {return this->t[0];}
        inline float y() const {return this->t[1];}
        inline float z() const {return this->t[2];}
        inline float w() const {return this->t[3];}

        std::string to_str();

        Vector operator- ();

        // Compute the magnitude of the vector
        float magnitude();
        // Normalize the vector
        Vector normalize();
        // Compute the dot product with another vector
        float dot(Vector);
};
} //namespace rtm

#endif