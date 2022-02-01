#ifndef CHECKERPATTERN_H
#define CHECKERPATTERN_H

#include "pattern.h"

namespace rtm
{
class CheckerPattern : public Pattern
{
    public:
        CheckerPattern();
        CheckerPattern(const Color& a, const Color& b);
        CheckerPattern(Pattern* a, Pattern* b);

        Color pattern_at(const Point& point) const override;
};
} // namespace rtm

#endif