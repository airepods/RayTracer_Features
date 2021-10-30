#include "canvas/canvas.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
using namespace rtm;

Canvas::Canvas()
{}

Canvas::Canvas(int width, int height) : _width(width), _height(height)
{
    board = new Color*[width];

    for(int i=0; i<width; ++i)
    {
        board[i] = new Color[height];
    }

    for(int i=0; i<width; ++i)
    {
        for(int j=0; j<height; ++j)
        {
            board[i][j] = Color(0, 0, 0);
        }
    }
}

Canvas::~Canvas()
{
    for(int i=0; i<_width; ++i)
    {
        delete[] board[i];
    }
    delete[] board;
}

string Canvas::to_str()
{
    string out = "";

    out += "P3\n";
    out += to_string(_width) + " ";
    out += to_string(_height) + "\n";
    out += "255\n";

    for(int i=0; i<_height; ++i)
    {
        int CH_LEFT = 70;
        for(int j=0; j<_width; ++j)
        {
            if(CH_LEFT < 11)
            {
                out += "\n";
                CH_LEFT = 70;
            }
            
            string c = board[j][i].to_str();
            out += c;

            CH_LEFT -= c.size(); 

            out += " ";
            CH_LEFT-=1;
        }
        out += "\n";
    }
    return out;
}

void Canvas::debug_print()
{
    for(int i=0; i<_height; ++i)
    {
        for(int j=0; j<_width; ++j)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
}

void Canvas::write_pixel(int x, int y, Color color)
{
    int r, g, b;
    Color c;

    r = round(color.red()*255);
    if(r > 255)
        r = 255;
    if(r < 0)
        r = 0;

    g = round(color.green()*255);
    if(r > 255)
        r = 255;
    if(r < 0)
        r = 0;

    b = round(color.blue()*255);
    if(r > 255)
        r = 255;
    if(r < 0)
        r = 0;
    
    c = Color(r, g, b);

    if(x >= _width)
        x = _width-1;
    
    if(x < 0)
        x = 0;

    if(y >= _height)
        y = _height-1;
    
    if(y < 0)
        y = 0;

    board[x][y] = c;
}

Color Canvas::pixel_at(int x, int y)
{
    return board[x][y];
}

void Canvas::export_to_ppm()
{
    // Initialize ofstream
    ofstream out ("picture.ppm");

    // Write into a file
    cout<<"Writing canvas into ppm file..."<<endl;
    out<<this->to_str();
    cout<<"picture.ppm has been created";

    // Close ofstream
    out.close();
}