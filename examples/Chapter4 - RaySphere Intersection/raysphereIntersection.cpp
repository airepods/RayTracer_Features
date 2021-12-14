#include "rtmlib.h"
#include <iostream>
#include <vector>

using namespace std;

void print_matrix(const rtm::Matrix& M)
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

int main()
{    
    // object
    rtm::Sphere sphere;
    sphere.transform(rtm::rotation_z(90) * rtm::scaling(0.5, 1, 1));

    // wall
    float wall_z = 10;

    float wall_size = 7;
    float canvas_pixels = 100;

    float pixel_size = wall_size/canvas_pixels;
    float half = wall_size/2;

    // ray origin
    rtm::Point ray_origin(0, 0, -5);

    // canvas
    rtm::Canvas canvas(canvas_pixels, canvas_pixels);


    cout<<"Starting rendering..."<<endl;

    for(int y=0; y<canvas_pixels; ++y)
    {
        float world_y = half - pixel_size * y;
        
        for(int x=0; x<canvas_pixels; ++x)
        {
            float world_x = -half + pixel_size * x;

            rtm::Point position(world_x, world_y, wall_z);

            rtm::Ray ray(ray_origin, rtm::normalize((position - ray_origin)));

            // ray-sphere intersection
            auto intersection = sphere.intersects(ray);
            if(rtm::hit(intersection))
            {
                canvas.write_pixel(x, y, rtm::Color(0, 0, 1));
            }

        }

        cout<<"Progress "<<y<<"%"<<endl;
    }

    canvas.export_to_ppm();

    cout<<"Process completed!"<<endl;
}