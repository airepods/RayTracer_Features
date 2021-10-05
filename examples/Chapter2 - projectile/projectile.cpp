#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cmath>
#include "rtmlib.h"

using namespace std;

class Projectile
{
    public:
        Point position;
        Vector velocity;

        Projectile()
        {}

        Projectile(Point pos, Vector vel) : position(pos), velocity(vel) 
        {}
};

class Environment
{
    public:
        Vector gravity;
        Vector wind;

        Environment()
        {}

        Environment(Vector grav, Vector w) : gravity(grav), wind(w)
        {}

};

Projectile tick(Environment env, Projectile proj)
{
    Point position = proj.position + proj.velocity;
    Vector velocity = proj.velocity + env.gravity + env.wind;

    return Projectile(position, velocity);
}


int main()
{

    const int WIDTH = 800;
    const int HEIGHT = 600;
    const Color RED = Color(1, 0, 0);

    // Initialize ofstream
    ofstream out ("picture.ppm");

    // Initialize canvas
    Canvas canvas = Canvas(WIDTH, HEIGHT);

    Projectile p = Projectile(Point(0,1,0), normalize(Vector(1,2.5f,0))*9.5);
    Environment e = Environment(Vector(0, -0.1, 0), Vector(-0.01,0,0));

    canvas.write_pixel(p.position.x(), HEIGHT-p.position.y(), RED);

    int ticks = 1;
    float y_position = p.position.y();
    while(y_position > 0)
    {
        int x, y;
        Projectile newProjectile = tick(e, p);
        //cout<<"Tick "<<ticks<<endl;
        //cout<<"Projectile's y position = "<<newProjectile.position.y()<<endl;

        x = static_cast<int>(newProjectile.position.x());
        y = static_cast<int>(HEIGHT - newProjectile.position.y());
        //cout<<x<<", "<<y<<endl;
        canvas.write_pixel(x, y, RED);

        y_position = newProjectile.position.y();
        p = newProjectile;

        ticks+=1;
    }

    cout<<"Total ticks used: "<<ticks<<endl;

    // Write canvas into output.ppm
    cout<<"Writing canvas into ppm file..."<<endl;
    out<<canvas.to_str();
    cout<<"picture.ppm has been created";

    // Close ofstream
    out.close();

    return 0;
}