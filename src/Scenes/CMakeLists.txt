cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(raytracer-plugins-entity-sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(AmbientLight PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

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

target_sources(camera PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SceneState.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/Displayable.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SceneLoader.cpp"
)

target_sources(AmbientLight PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneState.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Displayable.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneLoader.cpp"
)

target_sources(raytracer-plugins-entity-sphere PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneState.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Displayable.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneLoader.cpp"
)

target_sources(Plane PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneState.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Displayable.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/SceneLoader.cpp"
)
