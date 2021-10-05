#ifndef CANVAS_H    
#define CANVAS_H

#include "mat_entities/color.h"
#include <string>

class Canvas
{
    private:
        int _width;
        int _height;
        Color** board;
    public:
        Canvas();
        Canvas(int width, int height);
        ~Canvas();

        std::string to_str();
        void debug_print();

        void write_pixel(int x, int y, Color);
        Color pixel_at(int x, int y);

        void export_to_ppm();
};

#endif