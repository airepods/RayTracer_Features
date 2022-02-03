#define _USE_MATH_DEFINES

#include "util/utils.h"
#include "mat_constants/math_constants.h"
#include <string>
#include <sstream>
#include <cmath>

using namespace std;
using namespace rtm;

// Compare two floating point numbers
bool rtm::fcompare(const double& a, const double& b)
{
    if(abs(a - b) < rtm::constants::epsilon)
        return true;
    else
        return false;
}

// Convert float to string with fixed decimal places
string rtm::ftos(const float& f, const int& nd)
{
   ostringstream ostr;
   int tens = stoi("1" + string(nd, '0'));
   ostr << round(f*tens)/tens;
   return ostr.str();
}

// Convert double to string with fixed decimal places
string rtm::dtos(const double& f, const int& nd)
{
   ostringstream ostr;
   int tens = stoi("1" + string(nd, '0'));
   ostr << round(f*tens)/tens;
   return ostr.str();
}

// Convert an angle from degrees to radians
float rtm::to_radians(const float& degrees)
{
    return (degrees/180)*M_PI;
}

// Return null pointer
void* rtm::empty_array()
{
    return nullptr;
}