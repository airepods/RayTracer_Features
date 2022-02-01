#include "patterns/ringPattern.h"

using namespace rtm;

RingPattern::RingPattern(const Color& a, const Color& b) : Pattern(a, b)
{}

Color RingPattern::pattern_at(const Point& point) const
{
    // stripe pattern only affects x coordinate
    double sum = std::pow(point.x(), 2) + std::pow(point.z(), 2);
    double sqr_val = std::sqrt(sum);
    int floor_root = static_cast<int>(std::floor(sqr_val));
    if(floor_root % 2 == 0)
        return m_a;

    return m_b;
}