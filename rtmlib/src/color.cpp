#include "mat_entities/color.h"
#include "util/utils.h"
#include <string>

using namespace std;
using namespace rtm;

// Default constructor
Color::Color()
{}

// Custom constructor, construct a pixel RGB
Color::Color(const double& red, const double& green, const double& blue) : Tuple(red, green, blue)
{}

// Construct a color from an array of pixels/elements
Color::Color(double* elements) : Tuple(elements)
{}

// Return a string of the RGB color 
string Color::to_str() const
{
    string out = "";

    int i;
    for(i=0; i<2; ++i)
    {
        out += dtos(t[i], 2) + " ";
    }
    out += dtos(t[i], 2);

    return out;
}

// Pixelwise multiplication of colors
Color Color::operator*(const Color& c) const
{
    double r = this->red()   * c.red();
    double g = this->green() * c.green();
    double b = this->blue()  * c.blue();

    return Color(r, g, b);
}