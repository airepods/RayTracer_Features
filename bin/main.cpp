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

int main()
{    
    Sphere s;

    Intersection<Sphere> i1(5, s);
    Intersection<Sphere> i2(7, s);
    Intersection<Sphere> i3(-3, s);
    Intersection<Sphere> i4(2, s);


    vector<Intersection<Sphere>> intersections{i1, i2, i3, i4};

    auto i = hit(intersections);

    if(i == nullptr)
        cout<<"Nothing"<<endl;
    else
    {
        cout<<i->get_t_value()<<endl;
        delete i;
    }
        
    
    // if(l == empty_array())
    //     cout<<"Empty"<<endl;
    // else
    // {
    //     cout<<"x0 = "<<l[0]<<endl;
    //     cout<<"x1 = "<<l[1]<<endl;
    // }




    return 0;
}