cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(raytracer-plugins-entity-sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/EntityFactory.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/FilterFactory.cpp"
)
