cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SpotLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_ray PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_image PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(ray_transform PRIVATE
    Transform.cpp
    Vector3f.cpp
    Vector2i.cpp
)

target_sources(raytracer PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Sphere PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Camera PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(AmbientLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Plane PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(LimitedCone PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Cone PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(PointLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(SpotLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Cylinder PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(LimitedCylinder PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(SSAAx4 PRIVATE $<TARGET_OBJECTS:ray_transform>)
