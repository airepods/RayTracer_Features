project(rtmlib)

# Add library source files
add_library(${PROJECT_NAME} 
                src/canvas.cpp
                src/color.cpp
                src/geo_test.cpp
                src/matrix.cpp
                src/point.cpp
                src/ray.cpp
                src/sphere.cpp
                src/transforms.cpp
                src/tuple.cpp
                src/vector.cpp
                src/utils.cpp)

# Include directories for header files
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)