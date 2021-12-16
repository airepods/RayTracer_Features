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
                src/ray_transform.cpp
                src/ray.cpp
                src/sphere.cpp
                src/transforms.cpp
                src/tuple.cpp
                src/tuple_utility.cpp
                src/vector.cpp
                src/utils.cpp
                src/pointLight.cpp
                src/material.cpp
                src/light.cpp)

# Include directories for header files
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)