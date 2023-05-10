cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    Display.cpp
)

find_library(SFML_graphics sfml-graphics)
find_library(SFML_window sfml-window)
find_library(SFML_system sfml-system)
set(LIB_sfml ${SFML_graphics} ${SFML_window} ${SFML_system})
target_link_libraries(raytracer PRIVATE ${LIB_sfml})

add_subdirectory(Modules)