cmake_minimum_required(VERSION 3.13)
project(Raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer engine with sphere,..."
    LANGUAGES CXX
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------- Entities plugins ---------
add_library(raytracer-plugins-entity-sphere SHARED)
set_target_properties(raytracer-plugins-entity-sphere PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/EntitiesPlugins"
)
add_library(AmbientLight SHARED)
set_target_properties(AmbientLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
# --------- Filters plugins ---------


# -----------------------------------
# --------- Main executable ---------

add_executable(raytracer)
set_target_properties(raytracer PROPERTIES
    CXX_STANDARD 20
)

add_subdirectory(PluginsExt)
add_subdirectory(src)
