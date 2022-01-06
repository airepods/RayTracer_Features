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
    auto light = rtm::PointLight(rtm::Point(-5, 1, -8), rtm::Color(1, 1, 1));

    // wall
    auto wall = new rtm::Sphere();
    // floor transform
    wall->set_transform(rtm::translation(0.5, 0, 1.5) * rtm::scaling(20, 20, 0.01));
    // floor material
    auto matwall = rtm::Material();
    matwall.set_color(rtm::Color(1, 0.9, 0.9));
    matwall.set_specular(0);
    wall->set_material(matwall);

    // middle 
    auto middle = new rtm::Sphere();
    // middle transform
    middle->set_transform(rtm::translation(-1.85, 1, -1) * rtm::scaling(0.65, 0.5, 0.7));
    // middle material
    auto matmiddle = rtm::Material();
    matmiddle.set_color(rtm::Color(0.1, 1, 0.5));
    matmiddle.set_diffuse(0.7);
    matmiddle.set_specular(0.3);
    middle->set_material(matmiddle);

    // head 
    auto head = new rtm::Sphere();

    head->set_transform(rtm::translation(-1.3, 1.3, -1.25) * rtm::scaling(0.45, 0.45, 0.45));

    auto mathead = rtm::Material();
    mathead.set_color(rtm::Color(1, 1, 0.5));
    mathead.set_diffuse(0.7);
    mathead.set_specular(0.3);
    head->set_material(mathead);

    // tail 
    auto tail = new rtm::Sphere();
    tail->set_transform(rtm::translation(-2.45, 1.2, -0.5) * rtm::scaling(0.3, 0.3, 0.3));
    tail->set_material(matmiddle);

    // ear
    auto ear = new rtm::Sphere();
    ear->set_transform(rtm::translation(-1.35, 1.9, -1) * rtm::rotation_z(rtm::PI()/8) * rtm::scaling(0.1, 0.3, 0.3));
    ear->set_material(mathead);

    // mouth
    auto mouth = new rtm::Sphere();
    mouth->set_transform(rtm::translation(-1.1, 1.2, -1.7) * rtm::scaling(0.12, 0.12, 0.12));
    auto matmouth = rtm::Material();
    matmouth.set_color(rtm::Color(1, 0, 0));
    matmouth.set_diffuse(0.7);
    matmouth.set_specular(0.3);
    mouth->set_material(matmouth);



    vector<rtm::Surface*> surfaces = {wall, middle, head, tail, ear, mouth};

    auto world = rtm::World(light, surfaces);
    auto c = rtm::Camera(1024, 768, rtm::PI()/3);
    
    auto from = rtm::Point(3, 1.5, -5);
    auto to = rtm::Point(0, 1, 0);
    auto up = rtm::Vector(0, 1, 0);
    c.set_transform(rtm::view_transform(from, to, up));

    rtm::Scene scene;
    auto image = rtm::Scene::Render(c, world);

    image.export_to_ppm();
    
    return 0;
}