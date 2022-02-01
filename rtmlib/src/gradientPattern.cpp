#include "patterns/gradientPattern.h"
#include <cmath>

using namespace rtm;

GradientPattern::GradientPattern()
{}

GradientPattern::GradientPattern(const Color& a, const Color& b) : Pattern(a, b)
{}

Color GradientPattern::pattern_at(const Point& point) const
{
    auto distance = m_b - m_a;
    auto fraction = point.x() - std::floor(point.x());
    return m_a + distance * fraction;
}