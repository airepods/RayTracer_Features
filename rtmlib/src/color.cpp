#include "mat_entities/color.h"
#include "util/utils.h"
#include <string>

using namespace std;
using namespace rtm;

Color::Color()
{}

Color::Color(float red, float green, float blue) : Tuple(red, green, blue)
{}

Color::Color(float* elements) : Tuple(elements)
{}

string Color::to_str()
{
    string out = "";

    int i;
    for(i=0; i<2; ++i)
    {
        out += ftos(t[i], 2) + " ";
    }
    out += ftos(t[i], 2);

    return out;
}

Color Color::operator*(Color c)
{
    float r = this->red()   * c.red();
    float g = this->green() * c.green();
    float b = this->blue()  * c.blue();

    return Color(r, g, b);
}