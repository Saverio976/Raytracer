cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedPlane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(Camera PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(AmbientLight PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(Sphere PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(Plane PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(LimitedPlane PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(Cone PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(PointLight PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(Cylinder PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
)

target_sources(LimitedCylinder PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
)

target_sources(SSAAx4 PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
)
