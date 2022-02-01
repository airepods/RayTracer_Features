#ifndef GRADIENTPATTERN_H
#define GRADIENTPATTERN_H

#include "pattern.h"

namespace rtm
{
class GradientPattern : public Pattern
{
    public:
        GradientPattern();
        GradientPattern(const Color& a, const Color& b);

        Color pattern_at(const Point& point) const override;
};
} // namespace rtm

#endif