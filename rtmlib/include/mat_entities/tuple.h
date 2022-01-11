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
        double t[4];
    public:
        Tuple();
        Tuple(const double& x, const double& y, const double& z);
        Tuple(const double& x, const double& y, const double& z, const double& w);
        Tuple(double* elements);

        virtual std::string to_str() const = 0;

        // Compare if two tuples are equal
        template<class T>
        bool is_equal_to(const T& tuple) const
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