cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Transform)
