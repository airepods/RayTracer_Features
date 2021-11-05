#include "mat_entities/color.h"
#include "util/utils.h"
#include <string>

using namespace std;
using namespace rtm;

// Default constructor
Color::Color()
{}

// Custom constructor, construct a pixel RGB
Color::Color(float red, float green, float blue) : Tuple(red, green, blue)
{}

// Construct a color from an array of pixels/elements
Color::Color(float* elements) : Tuple(elements)
{}

// Return a string of the RGB color 
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

// Pixelwise multiplication of colors
Color Color::operator*(const Color& c)
{
    float r = this->red()   * c.red();
    float g = this->green() * c.green();
    float b = this->blue()  * c.blue();

    return Color(r, g, b);
}