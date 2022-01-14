#include "patterns/pattern_functions.h"
#include "patterns/pattern.h"
#include <cmath>

using namespace rtm;

Pattern rtm::stripe_pattern(const Color& a, const Color& b)
{
    Pattern pattern;
    pattern.a = a;
    pattern.b = b;

    return pattern;
}

Color rtm::stripe_at(const Pattern& pattern, const Point& point)
{
    // stripe pattern only affects x coordinate
    int floor_x = static_cast<int>(std::floor(point.x()));
    if(floor_x % 2 == 0)
        return pattern.a;

    return pattern.b;
}