cmake_minimum_required(VERSION 3.13)
project(Raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer engine with sphere,..."
    LANGUAGES CXX
)
set(CMAKE_BUILD_TYPE Release)
if (NOT CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# --------- Entities plugins ---------
add_library(Sphere SHARED)
set_target_properties(Sphere PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(Camera SHARED)
set_target_properties(Camera PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(AmbientLight SHARED)
set_target_properties(AmbientLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(Plane SHARED)
set_target_properties(Plane PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(LimitedPlane SHARED)
set_target_properties(LimitedPlane PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(PointLight SHARED)
set_target_properties(PointLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(Cylinder SHARED)
set_target_properties(Cylinder PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
add_library(LimitedCylinder SHARED)
set_target_properties(LimitedCylinder PROPERTIES
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
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)

add_subdirectory(PluginsExt)
add_subdirectory(src)
