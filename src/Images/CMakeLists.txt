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
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PlainMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(TransparencyMaterial PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCustom PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(CameraCluster PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pipeline PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(ray_image_pixelthread PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(ray_image_color PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
)

target_sources(ray_image_ray PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
)

target_sources(ray_image_image PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
)

target_sources(ray_image_pipeline PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
)

target_sources(ray_image_pixelthread PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(raytracer PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_image>
)

target_sources(Camera PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
    $<TARGET_OBJECTS:ray_image_image>
    $<TARGET_OBJECTS:ray_image_pipeline>
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    $<TARGET_OBJECTS:ray_image_pixelthread>
)

target_sources(CameraCustom PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_image>
    $<TARGET_OBJECTS:ray_image_pipeline>
    $<TARGET_OBJECTS:ray_image_ray>
    $<TARGET_OBJECTS:ray_image_pixelthread>
)

target_sources(CameraCluster PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_image>
    $<TARGET_OBJECTS:ray_image_pipeline>
    $<TARGET_OBJECTS:ray_image_ray>
    $<TARGET_OBJECTS:ray_image_pixelthread>
)

target_sources(AmbientLight PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(Sphere PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(Plane PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(LimitedPlane PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(Disk PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(Cone PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(LimitedCone PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(PointLight PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(SpotLight PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(PlainMaterial PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(TransparencyMaterial PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
    $<TARGET_OBJECTS:ray_image_pixelthread>
)

target_sources(Cylinder PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(LimitedCylinder PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_ray>
)

target_sources(SSAAx4 PRIVATE
    $<TARGET_OBJECTS:ray_image_color>
    $<TARGET_OBJECTS:ray_image_image>
)
