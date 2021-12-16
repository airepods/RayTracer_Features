#include "canvas/canvas.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;
using namespace rtm;

// Default constructor
Canvas::Canvas() : board(nullptr)
{}

// Custom constructor, it allocates memory for the canvas board
// the default canvas is black (every pixel is 0, 0, 0)
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

// Destructor
Canvas::~Canvas()
{
    if(board != nullptr)
    {
        for(int i=0; i<_width; ++i)
        {
            delete[] board[i];
        }
        delete[] board;
    }
}

// Copy constructor, copy the contents of board into a the new instance's board member
// data, make sure to copy the contents and no the pointers otherwise the two instances
// will point to the same memory address 
Canvas::Canvas(const Canvas& c)
{
    _width = c._width;
    _height = c._height;

    board = new Color*[_width];

    for(int i=0; i<_width; ++i)
    {
        board[i] = new Color[_height];
    }

    for(int i=0; i<_width; ++i)
    {
        for(int j=0; j<_height; ++j)
        {
            board[i][j] = c.board[i][j];
        }
    }
}

// Copy assignment operator, same at copy constructor
Canvas& Canvas::operator= (const Canvas& c)
{
    _width = c._width;
    _height = c._height;

    board = new Color*[_width];

    for(int i=0; i<_width; ++i)
    {
        board[i] = new Color[_height];
    }

    for(int i=0; i<_width; ++i)
    {
        for(int j=0; j<_height; ++j)
        {
            board[i][j] = c.board[i][j];
        }
    }

    return *this;
}

// Return a string with the content formated for a ppm file
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

// Testing purposes only, print a matrix of asterisk for validation
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

// Write a pixel into the canvas given its x and y positions and a color
// Every color greater than 255 will be considered at 255, and for colors less
// than 0, they will be considered as 0
void Canvas::write_pixel(int x, int y, const Color& color)
{
    int r, g, b;
    Color c;

    r = round(color.red()*255);
    if(r > 255)
        r = 255;
    if(r < 0)
        r = 0;

    g = round(color.green()*255);
    if(g > 255)
        g = 255;
    if(r < 0)
        g = 0;

    b = round(color.blue()*255);
    if(b > 255)
        b = 255;
    if(b < 0)
        b = 0;
    
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

// Return a specific pixel given the x and y positions of the canvas
Color Canvas::pixel_at(int x, int y)
{
    return board[x][y];
}

// Export canvas to ppm file
void Canvas::export_to_ppm()
{
    // Initialize ofstream
    ofstream out ("picture.ppm");

    // Write into a file
    cout<<"Writing canvas into ppm file..."<<endl;
    out<<this->to_str();
    cout<<"picture.ppm has been created\n";

    // Close ofstream
    out.close();
}