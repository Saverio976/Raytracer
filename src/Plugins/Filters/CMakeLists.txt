cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedPlane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Disk PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Triangle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SpotLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Torus PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Obj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCustom PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCluster PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(BlackAndWhite PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/FilterLoader.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/FilterHandler.cpp"
)
