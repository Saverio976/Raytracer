cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedPlane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Disk PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SpotLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Triangle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Torus PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Obj PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PlainMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(RefractionMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(TransparencyMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ChessBoardMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ZebraMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(MirrorMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_ray PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_image PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCustom PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCluster PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pipeline PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pixelthread PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(BlackAndWhite PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(ray_transform PRIVATE
    Transform.cpp
    Vector3f.cpp
    Vector2i.cpp
)

target_sources(raytracer PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Sphere PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Camera PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(AmbientLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(LimitedPlane PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Disk PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Plane PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(LimitedCone PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Cone PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Plane PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Triangle PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(PointLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(SpotLight PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Cylinder PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Torus PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(Obj PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(PlainMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(RefractionMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(TransparencyMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(ChessBoardMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(ZebraMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(MirrorMaterial PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(LimitedCylinder PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(SSAAx4 PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(BlackAndWhite PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(CameraCustom PRIVATE $<TARGET_OBJECTS:ray_transform>)

target_sources(CameraCluster PRIVATE $<TARGET_OBJECTS:ray_transform>)
