cmake_minimum_required(VERSION 3.13)
project(Raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer engine with sphere,..."
    LANGUAGES CXX
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(raytracer-plugins-entity-sphere SHARED)
set_target_properties(raytracer-plugins-entity-sphere PROPERTIES
    CXX_STANDARD 20
)

add_executable(raytracer)
set_target_properties(raytracer PROPERTIES
    CXX_STANDARD 20
)

add_subdirectory(PluginsExt)
add_subdirectory(src)
