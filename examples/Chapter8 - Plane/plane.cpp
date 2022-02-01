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

    // right
    auto right = new rtm::Sphere();
    // right transform
    right->set_transform(rtm::translation(1, 0.5, 1.2) * rtm::scaling(0.5, 0.5, 0.5));
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

    // left 
    auto left = new rtm::Sphere();
    // left transform
    left->set_transform(rtm::translation(-1.5, 0.33, -0.75) * rtm::scaling(0.33, 0.33, 0.33));
    // left material
    auto matleft = rtm::Material();
    matleft.set_color(rtm::Color(1, 0.8, 0.1));
    matleft.set_diffuse(0.7);
    matleft.set_specular(0.3);
    left->set_material(matleft);

    // floor
    auto floor = new rtm::Plane();

    vector<rtm::Surface*> surfaces = {floor, right, middle, left};

    auto world = rtm::World(light, surfaces);
    auto c = rtm::Camera(500, 250, rtm::constants::pi/3);
    
    auto from = rtm::Point(3, 1.5, -5);
    auto to = rtm::Point(0, 1, 0);
    auto up = rtm::Vector(0, 1, 0);
    c.set_transform(rtm::view_transform(from, to, up));

    rtm::Scene scene;
    auto image = rtm::Scene::Render(c, world);

    image.export_to_ppm();
    
    return 0;
}