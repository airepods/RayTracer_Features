#ifndef POINT_H    
#define POINT_H

#include "mat_entities/tuple.h"
#include <string>

namespace rtm
{
class Point : public Tuple
{
    public:
        Point();
        Point(float x, float y, float z);
        Point(float x, float y, float z, float w);
        Point(float* elements);

        inline float x() const {return this->t[0];}
        inline float y() const {return this->t[1];}
        inline float z() const {return this->t[2];}
        inline float w() const {return this->t[3];}

        std::string to_str();

        Point operator- ();
};
} //namespace rtm

#endif