#include "patterns/checkerPattern.h"
#include <cmath>

using namespace rtm;

CheckerPattern::CheckerPattern()
{}

CheckerPattern::CheckerPattern(const Color& a, const Color& b) : Pattern(a, b)
{}

CheckerPattern::CheckerPattern(Pattern* a, Pattern* b) : Pattern(a, b)
{}

Color CheckerPattern::pattern_at(const Point& point) const
{
    auto floor_sum = static_cast<int>( std::floor(point.x()) + std::floor(point.y()) + std::floor(point.z()) );
    
    if(patterns_are_defined()) 
        return floor_sum % 2 == 0 ? m_pattern_a->pattern_at_object(point) : m_pattern_b->pattern_at_object(point);
    else
        return floor_sum % 2 == 0 ? m_a : m_b;
}