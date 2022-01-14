#ifndef PATTERN_FUNCTIONS_H    
#define PATTERN_FUNCTIONS_H

#include "pattern.h"
#include "mat_entities/color.h"
#include "mat_entities/point.h"

namespace rtm
{
    Pattern stripe_pattern(const Color& a, const Color& b);
    Color stripe_at(const Pattern& pattern, const Point& point);
}

#endif