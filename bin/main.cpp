#include "rtmlib.h"
#include <iostream>
#include <vector>

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

int main()
{    
    
    Ray ray(Point(0, 0, 5), Vector(0, 0, 1));
    Sphere s;
    Cube c;

    // Intersection<Sphere> i1(-10, s);
    // Intersection<Sphere> i2(-1, s);
    // Intersection<Sphere> i3(1, s);
    // Intersection<Sphere> i4(0.5, s);

    // vector<Intersection<Sphere>> xs = {i1, i2, i3, i4};
    // Intersection<Sphere> output;

    // if(hit(xs, output))
    //     cout<<"T value: "<<output.get_t()<<"\n"<<"Object: "<<output.get_object_type().type_to_str()<<"\n";
    // else
    //     cout<<"No hit"<<endl;

    Intersection i1(-10, &s);
    Intersection i2(-1, &s);
    Intersection i3(2, &c);

    vector<Intersection*> xs = {&i1, &i2, &i3};

    for (int i = 0; i < xs.size(); i++)
    {
        cout<<"T value: "<<xs[i]->get_t()<<"\n";
        cout<<"Object: "<<xs[i]->get_shape()->get_object_type()->type_to_str()<<"\n";
    }
    

    // if(l == empty_array())
    //     cout<<"Empty"<<endl;
    // else
    // {
    //     cout<<"x0 = "<<l[0]<<endl;
    //     cout<<"x1 = "<<l[1]<<endl;
    // }

    cout<<"Program completed"<<endl;
    return 0;
}