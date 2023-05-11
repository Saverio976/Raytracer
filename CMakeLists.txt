cmake_minimum_required(VERSION 3.18)
project(Raytracer
    VERSION 1.0
    DESCRIPTION "Raytracer engine with sphere,..."
    LANGUAGES CXX
)
set(CMAKE_BUILD_TYPE Release)
if (NOT CMAKE_BUILD_TYPE STREQUAL Release)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# --------- Entities plugins ---------
# SPHERE
add_library(Sphere SHARED)
set_target_properties(Sphere PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Sphere PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# CAMERA
add_library(Camera SHARED)
set_target_properties(Camera PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Camera PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# CAMERA CUSTOM
add_library(CameraCustom SHARED)
set_target_properties(CameraCustom PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(CameraCustom PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# CAMERA CLUSTER
add_library(CameraCluster SHARED)
set_target_properties(CameraCluster PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(CameraCluster PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# AMBIENT LIGHT
add_library(AmbientLight SHARED)
set_target_properties(AmbientLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(AmbientLight PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# PLANE
add_library(Plane SHARED)
set_target_properties(Plane PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Plane PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# LIMITED PLANE
add_library(LimitedPlane SHARED)
set_target_properties(LimitedPlane PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(LimitedPlane PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# DISK
add_library(Disk SHARED)
set_target_properties(Disk PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Disk PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# CONE
add_library(Cone SHARED)
set_target_properties(Cone PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Cone PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# LIMITED CONE
add_library(LimitedCone SHARED)
set_target_properties(LimitedCone PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(LimitedCone PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# POINT LIGHT
add_library(PointLight SHARED)
set_target_properties(PointLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(PointLight PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# SPOT LIGHT
add_library(SpotLight SHARED)
set_target_properties(SpotLight PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(SpotLight PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# CYLINDER
add_library(Cylinder SHARED)
set_target_properties(Cylinder PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Cylinder PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# LIMITED CYLINDER
add_library(LimitedCylinder SHARED)
set_target_properties(LimitedCylinder PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(LimitedCylinder PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# TORUS
add_library(Torus SHARED)
set_target_properties(Torus PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Torus PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()
# TRIANGLE
add_library(Triangle SHARED)
set_target_properties(Triangle PROPERTIES
        CXX_STANDARD 20
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/EntitiesPlugins"
        )
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(Triangle PROPERTIES
            UNITY_BUILD true
            UNITY_BUILD_MODE BATCH
            )
endif()

# --------- Filters plugins ---------
add_library(SSAAx4 SHARED)
set_target_properties(SSAAx4 PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/FiltersPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(SSAAx4 PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# --------- Materials plugins ---------
add_library(PlainMaterial SHARED)
set_target_properties(PlainMaterial PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/MaterialsPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(PlainMaterial PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

add_library(ChessBoardMaterial SHARED)
set_target_properties(ChessBoardMaterial PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/MaterialsPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ChessBoardMaterial PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

add_library(ZebraMaterial SHARED)
set_target_properties(ZebraMaterial PROPERTIES
    CXX_STANDARD 20
    PREFIX ""
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/MaterialsPlugins"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ZebraMaterial PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# -----------------------------------
# --------- Main executable ---------

add_executable(raytracer)
set_target_properties(raytracer PROPERTIES
    CXX_STANDARD 20
    LINK_FLAGS "-Wl,--dynamic-list=${CMAKE_CURRENT_SOURCE_DIR}/exported.txt"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(raytracer PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# -----------------------------------
# ------------- Objects -------------

# src/Entities/Transform/{Vector2i,Vector3f,Transform}.cpp
add_library(ray_transform OBJECT)
set_target_properties(ray_transform PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_transform PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Image/Color.cpp
add_library(ray_image_color OBJECT)
set_target_properties(ray_image_color PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_image_color PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Image/Ray.cpp
add_library(ray_image_ray OBJECT)
set_target_properties(ray_image_ray PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_image_ray PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Image/Image.cpp
add_library(ray_image_image OBJECT)
set_target_properties(ray_image_image PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_image_image PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Image/ImagePipeLine.cpp
add_library(ray_image_pipeline OBJECT)
set_target_properties(ray_image_pipeline PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_image_pipeline PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Image/PixelThread.cpp
add_library(ray_image_pixelthread OBJECT)
set_target_properties(ray_image_pixelthread PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_image_pixelthread PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()

# src/Progress.cpp
add_library(ray_progress OBJECT)
set_target_properties(ray_progress PROPERTIES
    CXX_STANDARD 20
    POSITION_INDEPENDENT_CODE ON
)
if (CMAKE_BUILD_TYPE STREQUAL Release)
    set_target_properties(ray_progress PROPERTIES
        UNITY_BUILD true
        UNITY_BUILD_MODE BATCH
    )
endif()


# -----------------------------------
# ------------- rest .. -------------
# -----------------------------------

add_subdirectory(PluginsExt)
add_subdirectory(src)
