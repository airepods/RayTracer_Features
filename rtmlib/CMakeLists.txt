project(rtmlib)

# Add library source files
add_library(${PROJECT_NAME} 
                src/canvas.cpp
                src/color.cpp
                src/intersection.cpp
                src/matrix_utility.cpp
                src/matrix.cpp
                src/point.cpp
                src/surface.cpp
                src/ray_intersection.cpp
                src/ray.cpp
                src/sphere.cpp
                src/transforms.cpp
                src/tuple.cpp
                src/tuple_utility.cpp
                src/vector.cpp
                src/utils.cpp
                src/pointLight.cpp
                src/material.cpp
                src/light.cpp
                src/world.cpp
                src/prepare_computations.cpp
                src/camera.cpp
                src/scene.cpp
                src/plane.cpp
                src/pattern.cpp
                src/stripePattern.cpp
                src/gradientPattern.cpp
                src/ringPattern.cpp
                src/checkerPattern.cpp
                src/solidPattern.cpp
                src/box.cpp
                src/cylinder.cpp
                src/cone.cpp
                src/group.cpp
                src/triangle.cpp
                src/parser.cpp
                src/smoothTriangle.cpp)

# Include directories for header files
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)