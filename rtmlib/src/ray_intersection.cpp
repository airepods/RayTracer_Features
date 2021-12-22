#include "geometry/ray_intersection.h"
#include "mat_entities/tuple_utility.h"
#include <algorithm>

using namespace rtm;

bool rtm::hit(std::vector<Intersection*>& record, Intersection& intersection_ouput)
{
    std::sort(record.begin(), record.end(), [](Intersection* a, Intersection* b){return *a < *b;});

    for (auto&& current_intersection : record)
    {
        if(current_intersection->get_t() >= 0)
        {
            intersection_ouput = *current_intersection;
            return true;
        }
    }

    return false;
}

bool rtm::hit(std::vector<Intersection>& record, Intersection& intersection_ouput)
{
    std::sort(record.begin(), record.end(), [](Intersection a, Intersection b){return a < b;});

    for (auto&& current_intersection : record)
    {
        if(current_intersection.get_t() >= 0)
        {
            intersection_ouput = current_intersection;
            return true;
        }
    }

    return false;
}

bool rtm::hit(std::vector<Intersection>& record)
{
    std::sort(record.begin(), record.end(), [](Intersection a, Intersection b){return a < b;});

    for (auto&& current_intersection : record)
    {
        if(current_intersection.get_t() >= 0)
        {
            return true;
        }
    }

    return false;
}

Point rtm::position(const Ray& r, const float& t)
{
    return r.origin() + r.direction()*t;
}