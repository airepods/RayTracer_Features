#ifndef CANVAS_H    
#define CANVAS_H

#include "mat_entities/color.h"
#include <string>

namespace rtm
{
class Canvas
{
    private:
        int m_width;
        int m_height;
        Color** board;
    public:
        Canvas();
        Canvas(const int& width, const int& height);
        ~Canvas();

        Canvas(const Canvas&);
        Canvas& operator= (const Canvas&);

        std::string to_str() const;
        void debug_print() const;

        void write_pixel(int& x, int& y, const Color&) const;
        Color pixel_at(const int& x, const int& y) const;
        
        void export_to_ppm() const;
};
} //namespace rtm

#endif