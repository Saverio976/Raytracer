cmake_minimum_required(VERSION 3.13)

target_sources(raytracer-plugins-entity-sphere PRIVATE
        CameraEntity.cpp
    CameraCreator.cpp
    EntryPoint.cpp
)
