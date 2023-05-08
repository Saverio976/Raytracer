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
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(Sphere PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(Camera PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(AmbientLight PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(Plane PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(PointLight PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(Cylinder PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)

target_sources(LimitedCylinder PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector2i.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Transform.cpp"
)
