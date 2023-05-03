cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(raytracer-plugins-entity-sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)

target_sources(camera PRIVATE
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

target_sources(raytracer-plugins-entity-sphere PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ImagePipeLine.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/RayIterrator.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/PixelThread.cpp"
)
