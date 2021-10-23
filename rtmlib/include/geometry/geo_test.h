#ifndef GEO_TEST_H    
#define GEO_TEST_H

#include "primitives/sphere.h"
#include "geometry/ray.h"
#include "geometry/intersection.h"
#include <vector>

using namespace std;

Intersection<Sphere>* intersect(Sphere, Ray);
//Intersection<Sphere>* hit(vector<Intersection<Sphere>>);

#endif