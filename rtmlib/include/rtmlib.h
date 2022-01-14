#ifndef RTMLIB_H    
#define RTMLIB_H

#include "mat_constants/math_constants.h"

// mat_entities
#include "mat_entities/vector.h"
#include "mat_entities/point.h"
#include "mat_entities/color.h"
#include "mat_entities/matrix.h"
#include "mat_entities/tuple_utility.h"
#include "mat_entities/vector_utility.h"
#include "mat_entities/matrix_utility.h"

// canvas
#include "canvas/canvas.h"

// transforms
#include "transforms/transforms.h"

// geometry
#include "geometry/ray.h"
#include "geometry/intersections.h"
#include "geometry/intersection.h"
#include "geometry/ray_intersection.h"
#include "geometry/ray_transform.h"

// primitives
#include "primitives/surface.h"
#include "primitives/sphere.h"
#include "primitives/plane.h"

// light
#include "lighting/light.h"
#include "lighting/pointLight.h"

// materials
#include "materials/material.h"

// world
#include "worldScene/world.h"
#include "worldScene/camera.h"
#include "worldScene/scene.h"

// pre-computations
#include "computations/computation.h"
#include "computations/prepare_computations.h"

// patterns
#include "patterns/pattern_functions.h"
#include "patterns/pattern.h"

// utility
#include "util/utils.h"
#include "progress_bar/progressbar.hpp"

#endif