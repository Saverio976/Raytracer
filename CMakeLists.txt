cmake_minimum_required(VERSION 3.13)
project(Raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer engine with sphere,..."
    LANGUAGES CXX
)

add_executable(raytracer)
set_target_properties(raytracer PROPERTIES
    CXX_STANDARD 20
)

add_subdirectory(src)
