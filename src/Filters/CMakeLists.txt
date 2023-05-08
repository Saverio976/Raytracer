cmake_minimum_required(VERSION 3.17)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedPlane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    # sources of current directory
)
