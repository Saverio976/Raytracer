cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "../Images/Color.cpp"
    "Transform/Vector2i.cpp"
    "Transform/Vector3f.cpp"
)
