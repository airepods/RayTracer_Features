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
    // light
    auto light = rtm::PointLight(rtm::Point(-10, 10, -10), rtm::Color(1, 1, 1));

    // floor
    auto floor = new rtm::Sphere();
    // floor transform
    floor->set_transform(rtm::scaling(10, 0.01, 10));
    // floor material
    auto matfloor = rtm::Material();
    matfloor.set_color(rtm::Color(1, 0.9, 0.9));
    matfloor.set_specular(0);
    floor->set_material(matfloor);

    // left wall
    auto left_wall = new rtm::Sphere();
    // left wall transform
    left_wall->set_transform(rtm::translation(0, 0, 5) *
                             rtm::rotation_y(-rtm::PI()/4) *  rtm::rotation_x(rtm::PI()/2) *
                             rtm::scaling(10, 0.01, 10));
    // left wall material
    left_wall->set_material(matfloor);

    // right wall
    auto right_wall = new rtm::Sphere();
    // right wall transform
    right_wall->set_transform(rtm::translation(0, 0, 5) *
                              rtm::rotation_y(rtm::PI()/4) *  rtm::rotation_x(rtm::PI()/2) *
                              rtm::scaling(10, 0.01, 10));
    // right wall material
    right_wall->set_material(matfloor);

    // right
    auto right = new rtm::Sphere();
    // right transform
    right->set_transform(rtm::translation(1.5, 0.5, -0.5) * rtm::scaling(0.5, 0.5, 0.5));
    // right material
    auto matright = rtm::Material();
    matright.set_color(rtm::Color(0.5, 1, 0.1));
    matright.set_diffuse(0.7);
    matright.set_specular(0.3);
    right->set_material(matright);

    // middle 
    auto middle = new rtm::Sphere();
    // middle transform
    middle->set_transform(rtm::translation(-0.5, 1, 0.5));
    // middle material
    auto matmiddle = rtm::Material();
    matmiddle.set_color(rtm::Color(0.1, 1, 0.5));
    matmiddle.set_diffuse(0.7);
    matmiddle.set_specular(0.3);
    middle->set_material(matmiddle);

    vector<rtm::Surface*> surfaces = {floor, left_wall, right_wall, right, middle};

    auto world = rtm::World(light, surfaces);
    auto c = rtm::Camera(500, 250, rtm::PI()/3);
    
    auto from = rtm::Point(0, 1.5, -5);
    auto to = rtm::Point(0, 1, 0);
    auto up = rtm::Vector(0, 1, 0);
    c.set_transform(rtm::view_transform(from, to, up));

    rtm::Scene scene;
    auto image = rtm::Scene::Render(c, world);

    image.export_to_ppm();
    
    return 0;
}