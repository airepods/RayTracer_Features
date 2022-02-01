#include "patterns/stripePattern.h"

using namespace rtm;

StripePattern::StripePattern(const Color& a, const Color& b) : Pattern(a, b)
{}

Color StripePattern::pattern_at(const Point& point) const
{
    // stripe pattern only affects x coordinate
    int floor_x = static_cast<int>(std::floor(point.x()));
    if(floor_x % 2 == 0)
        return m_a;

    return m_b;
}