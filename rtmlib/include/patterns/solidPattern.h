#ifndef SOLIDPATTERN_H
#define SOLIDPATTERN_H

#include "pattern.h"

namespace rtm
{
class SolidPattern : public Pattern
{
    public:
        SolidPattern();
        SolidPattern(const Color& color);

        Color pattern_at(const Point& point) const override;
};
} // namespace rtm

#endif