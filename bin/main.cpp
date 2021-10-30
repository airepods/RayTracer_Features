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
    
    rtm::Ray ray(rtm::Point(1, 2, 3), rtm::Vector(0, 1, 0));
    rtm::Sphere s; 

    rtm::Matrix t = rtm::translation(3, 4, 5);

    auto t3 = t*ray.origin(); 
    auto t4 = t*ray.direction();  
    cout<<t3.to_str()<<endl;
    cout<<t4.to_str()<<endl;

    //Point o = t*Point(1, 2, 3);

    //auto d = t*ray.direction()
    //cout<<d.to_str()<<endl;

    cout<<"Program completed"<<endl;
    return 0;
}