#include "rtmlib.h"
#include <iostream>

using namespace std;

void print_matrix(Matrix M)
{
    const int ROW = M.get_nrow();
    const int COLUMN = M.get_ncolumn();

    for(int row=0; row<ROW; ++row)
    {
        for(int col=0; col<COLUMN; ++col)
        {
            cout<<M.at(row, col)<<" ";
        }
        cout<<endl;
    }
}

Point to_canvas_space(Point p, float radius, Vector center)
{
    return (radius * p) + center;
}

int main()
{    
    const int WIDTH = 400;
    const int HEIGHT = 400;

    Canvas canvas = Canvas(WIDTH, HEIGHT);
    const float radius = 0.375f * WIDTH;
    Vector CENTER = Vector(WIDTH/2, HEIGHT/2, 0);

    Matrix rotation = rotation_z(30);

    Point last = Point(-1, 0, 0);
    Point clock = to_canvas_space(last, radius, CENTER);

    for(int i=0; i<12; ++i)
    {
        Point next = rotation * last;
        Point clock = to_canvas_space(next, radius, CENTER);

        canvas.write_pixel(clock.x(), clock.y(), Color(1, 1, 1));
        last = next;
    }
    
    canvas.export_to_ppm();

    return 0;
}