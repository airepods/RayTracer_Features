#ifndef INTERSECTION_H    
#define INTERSECTION_H

#include "intersections.h"
#include "primitives/shape.h"
#include <vector>
#include <algorithm>
#include <string>

class Intersection : public Intersections
{
    private:
        float t;
        Shape* object = nullptr;
    public:
        Intersection();

        Intersection(float t_val , Shape* object_val);

        float get_t() override;
        Shape* get_shape() override; 

        // Useful for std::sort array of intersections 
        bool operator < (const Intersection& i) const;
};

// template <class T>
// bool hit(std::vector<T> record)
// {
//     std::sort(record.begin(), record.end());

//     for (auto&& current_intersection : record)
//     {
//         if(current_intersection.get_t() >= 0)
//         {
//             return true;
//         }
//     }

//     return false;
// }

bool hit(std::vector<Intersection*> record, Intersection& intersection_ouput);

#endif