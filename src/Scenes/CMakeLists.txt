cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCone PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(PointLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(LimitedCylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(SSAAx4 PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

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
