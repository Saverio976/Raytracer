cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

find_library(LIBCONFIG config++)
target_link_libraries(raytracer PRIVATE ${LIBCONFIG})

target_sources(raytracer PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ConfigWrapper.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SettingWrapper.cpp"
)
