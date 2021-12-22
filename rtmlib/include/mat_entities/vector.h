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

        inline void set_w(float w_val) { t[3] = w_val; }

        std::string to_str();

        Vector operator- () const;

        float magnitude() const;
        Vector normalize() const;
        float dot(const Vector&);
};
} //namespace rtm

#endif