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

    Intersection<Sphere> i1(10, s);
    Intersection<Sphere> i2(-1, s);

    vector<Intersection<Sphere>> xs = {i1, i2};
    Intersection<Sphere> i;

    if(hit(xs, i))
        cout<<"T value: "<<i.t<<"\n"<<"Object: "<<i.object.type_to_str()<<"\n";
    else
        cout<<"No hit"<<endl;

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