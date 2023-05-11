cmake_minimum_required(VERSION 3.13)

target_sources(ray_progress PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Progress.cpp"
)

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Parameters.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Logger.cpp"
    $<TARGET_OBJECTS:ray_progress>
)

target_sources(Camera PRIVATE
    $<TARGET_OBJECTS:ray_progress>
)

target_sources(CameraCustom PRIVATE
    $<TARGET_OBJECTS:ray_progress>
)

target_sources(CameraCluster PRIVATE
    $<TARGET_OBJECTS:ray_progress>
)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedPlane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Disk PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SpotLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PlainMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ChessBoardMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ZebraMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCustom PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCluster PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Triangle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pipeline PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Filters)
add_subdirectory(Entities)
add_subdirectory(Factories)
add_subdirectory(Images)
add_subdirectory(Plugins)
add_subdirectory(Scenes)
add_subdirectory(Display)
