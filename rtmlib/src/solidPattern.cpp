#include "patterns/solidPattern.h"

using namespace rtm;

SolidPattern::SolidPattern(const Color& color) : Pattern(color)
{}

Color SolidPattern::pattern_at(const Point& point) const
{
    return m_a; // m_a is only defined by the constructor, not m_b
}