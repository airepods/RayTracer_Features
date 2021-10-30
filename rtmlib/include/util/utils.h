#ifndef UTILS_H    
#define UTILS_H

#include "mat_entities/matrix.h"
#include <string>
#include <cmath>

namespace rtm
{
bool fcompare(float, float);
std::string ftos(float f, int nd);
float to_radians(float degrees);
void* empty_array();
} //namespace rtm

#endif