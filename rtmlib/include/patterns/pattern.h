#ifndef PATTERN_H    
#define PATTERN_H

#include "mat_entities/color.h"

namespace rtm
{
struct Pattern
{
    Color a;
    Color b;
    bool exists = false;
};
} // namespace rtm

#endif