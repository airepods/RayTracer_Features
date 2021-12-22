#ifndef UTILS_H    
#define UTILS_H

#include "mat_entities/matrix.h"
#include <string>
#include <cmath>

namespace rtm
{
bool fcompare(const float&, const float&);
std::string ftos(const float& f, const int& nd);
float to_radians(const float& degrees);
void* empty_array();
} //namespace rtm

#endif