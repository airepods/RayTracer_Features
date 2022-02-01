#ifndef RINGPATTERN_H    
#define RINGPATTERN_H

#include "pattern.h"

namespace rtm
{
class RingPattern : public Pattern
{
    public:
        RingPattern();
        RingPattern(const Color& a, const Color& b);

        Color pattern_at(const Point& point) const override;
};
} // namespace rtm

#endif