cmake_minimum_required(VERSION 3.13)

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Parameters.cpp"
)

add_subdirectory(Entities)
add_subdirectory(Factories)
add_subdirectory(Filters)
add_subdirectory(Images)
add_subdirectory(Plugins)
add_subdirectory(Scenes)
