#ifndef TUPLE_H    
#define TUPLE_H

#include "util/utils.h"
#include <string>

// Abstract class Tuple

namespace rtm
{
class Vector;
class Point;
class Color;

class Tuple
{
    protected:
        float t[4];
    public:
        Tuple();
        Tuple(float x, float y, float z);
        Tuple(float x, float y, float z, float w);
        Tuple(float* elements);

        virtual std::string to_str() = 0;

        // Compare if two tuples are equal
        template<class T>
        bool is_equal_to(const T& tuple)
        {
            for(int i=0; i<4; ++i)
            {
                if(!fcompare(t[i], tuple.t[i]))
                    return false;
            }
            return true;
        }
};
} //namespace rtm

#endif