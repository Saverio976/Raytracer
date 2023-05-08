cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/EntityLoader.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/EntityHandler.cpp"
)
