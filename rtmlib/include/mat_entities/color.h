#ifndef COLOR_H    
#define COLOR_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Color : public Tuple
{
    public:
        Color();
        Color(float red, float green, float blue);
        Color(float* elements);

        inline float red() {return this->t[0];}
        inline float green() {return this->t[1];}
        inline float blue() {return this->t[2];}

        inline float x() {return this->t[0];}
        inline float y() {return this->t[1];}
        inline float z() {return this->t[2];}

        std::string to_str();

        Color operator*(Color);
};
} //namespace rtm

#endif