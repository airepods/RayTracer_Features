#ifndef STRIPEPATTERN_H    
#define STRIPEPATTERN_H

#include "pattern.h"

namespace rtm
{
class StripePattern : public Pattern
{
    public:
        StripePattern();
        StripePattern(const Color& a, const Color& b);

        Color pattern_at(const Point& point) const override;
};
} // namespace rtm

#endif