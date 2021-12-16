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
    // create a new material
    auto material = rtm::Material();
    material.set_color(rtm::Color(1, 1, 1));

    // create a surface (sphere) and bind it to a material
    rtm::Sphere sphere;
    sphere.set_transform(rtm::scaling(1, 0.2, 2));
    sphere.set_material(material);

    // wall
    float wall_z = 10;

    float wall_size = 7;
    float canvas_pixels = 500;

    float pixel_size = wall_size/canvas_pixels;
    float half = wall_size/2;

    // ray origin
    rtm::Point ray_origin(0, 0, -5);

    // canvas
    rtm::Canvas canvas(canvas_pixels, canvas_pixels);

    // set the light source
    auto light_position = rtm::Point(-10, 5, -5);
    auto light_color = rtm::Color(1, 1, 1);
    auto light = rtm::PointLight(light_position, light_color);

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
            auto intersections = sphere.intersects(ray);
            auto hit_object = rtm::Intersection();

            if(rtm::hit(intersections, hit_object))
            {
                // get the intersection point 
                auto point = rtm::position(ray, hit_object.get_t());
                
                // compute the normal vector in that point in the sphere
                auto normal = hit_object.get_shape()->normal_at(point);

                // compute the eye vector
                auto eye = -ray.direction();

                // standard lighting model (compute the phong model for local ilumination)
                auto color = rtm::lighting(hit_object.get_shape()->get_material(), light, point, eye, normal);

                // write into canvas
                canvas.write_pixel(x, y, color);
            }

        }
        
        float progress = (y+1)*(100/canvas_pixels);
        if(progress == int(progress))
            cout<<"Progress "<<progress<<"%"<<endl;
    }

    canvas.export_to_ppm();

    cout<<"Process completed!"<<endl;
}