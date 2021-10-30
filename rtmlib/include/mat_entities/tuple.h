#ifndef TUPLE_H    
#define TUPLE_H

#include "util/utils.h"
#include <string>

namespace rtm
{
class Vector;
class Point;
class Color;

class Tuple
{
    protected:
        float t[4];
        int c[3];

    public:
        Tuple();
        Tuple(float x, float y, float z);
        Tuple(float x, float y, float z, float w);
        Tuple(float* elements);

        virtual std::string to_str() = 0;

        template<class T>
        bool is_equal_to(T tuple)
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