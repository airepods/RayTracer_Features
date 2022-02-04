#include "computations/prepare_computations.h"

#include "mat_constants/math_constants.h"

using namespace rtm;

namespace
{
    Vector reflect(const Vector& l, const Vector& normal) { return -l + 2*dot(l, normal)*normal; }
    
    std::list<Surface*>::const_iterator list_includes(const std::list<Surface*>& container, const Surface* object)
    {
        auto result = std::find(container.begin(), container.end(), object);   
        return result;
    }
}

Computation rtm::prepare_computations(const Intersection& i, const Ray& ray, std::vector<Intersection> xs)
{
    // instantiate a data structure for storing some precomputed values
    Computation comps;

    // copy the intersection's properties
    comps.tvalue = i.get_t();
    comps.surface = i.get_shape();

    // precompute some useful values
    comps.point = position(ray, comps.tvalue);
    comps.eyev = -ray.direction();
    comps.normalv = comps.surface->normal_at(comps.point);
    
    if(dot(comps.normalv, comps.eyev) < 0)
    {
        comps.inside = true;
        comps.normalv = -comps.normalv;
    }
    else
    {
        comps.inside = false;
    }

    comps.reflectv = reflect(-ray.direction(), comps.normalv);
    comps.over_point = comps.point + (comps.normalv * rtm::constants::epsilon);
    comps.under_point = comps.point - (comps.normalv * rtm::constants::epsilon);

    // Compute n1 and n2 refractive indices

    // hit is the intersection the ray hitted (i argument)
    auto hit = i;
    std::list<Surface*> container = {};

    for (auto &&i : xs)
    {
        if(i == hit) // if i is the hit
        {
            if(container.empty())
                comps.n1 = 1.0;
            else
                comps.n1 = container.back()->get_material().get_refractive_index();
        }

        // return an iterator to the position of the found object 
        // then remove that object from the list using the iterator
        auto it_position = list_includes(container, i.get_shape());
        if(it_position != container.end()) 
            container.erase(it_position);
        else // if the object is not in the list, add the object to the end of the list
            container.push_back(i.get_shape());
        
        if(i == hit) // if i is the hit
        {
            if(container.empty())
                comps.n2 = 1.0;
            else
                comps.n2 = container.back()->get_material().get_refractive_index();
            
            break;
        }
    }
     
    
    return comps;
}

