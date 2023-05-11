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
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SpotLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Triangle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PlainMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ChessBoardMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ZebraMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_transform PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_ray PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_color PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_image PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCustom PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCluster PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pipeline PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pixelthread PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

find_library(LIBCONFIG config++)
target_link_libraries(raytracer PRIVATE ${LIBCONFIG})

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SceneState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Displayable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SceneLoader.cpp"
)
