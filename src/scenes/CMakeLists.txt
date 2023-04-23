cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Box.cpp"
)
