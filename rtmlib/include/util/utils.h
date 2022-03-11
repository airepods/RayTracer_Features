#ifndef UTILS_H    
#define UTILS_H

#include <string>
#include <cmath>

namespace rtm
{
bool fcompare(const double&, const double&);
std::string ftos(const float& f, const int& nd);
std::string dtos(const double& f, const int& nd);
float to_radians(const float& degrees);
void* empty_array();
unsigned int countWordsInString(const std::string& str);

// inline double PI() {return 3.14159265;}
// inline float EPSILON() 
// {
//     float pow_10 = std::pow(10.0f, (float)4);
//     auto a = std::round(0.0001f * pow_10) / pow_10;
//     return std::round(0.0001f * pow_10) / pow_10;
// }
} //namespace rtm

#endif