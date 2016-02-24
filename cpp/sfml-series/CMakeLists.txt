# Project settings
cmake_minimum_required(VERSION 2.6)
project(sfml-series)

# Compiler settings
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
endif()
if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
endif()

# Includes and libraries settings
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

include(FindPkgConfig)

find_package(OpenGL REQUIRED)

find_package(SFML 2 REQUIRED graphics window system audio network)

# Executable settings
include_directories(${PROJECT_SOURCE_DIR}
    $(SFML_INCLUDE_DIR)
    ${OPENGL_INCLUDE_DIRS}
)

add_executable(bounce
    bounce.cpp
)

target_link_libraries(bounce
    ${SFML_LIBRARIES}
)

add_executable(primitives_shapes
    primitives_shapes.cpp
)

target_link_libraries(primitives_shapes
    ${SFML_LIBRARIES}
)

add_executable(random_rects
    random_rects.cpp
)

target_link_libraries(random_rects
    ${SFML_LIBRARIES}
)

add_executable(sfml_hello
    sfml_hello.cpp
)

target_link_libraries(sfml_hello
    ${SFML_LIBRARIES}
)

add_executable(simple_events
    simple_events.cpp
)

target_link_libraries(simple_events
    ${SFML_LIBRARIES}
)

add_executable(simple_graphics_sfml
    simple_graphics_sfml.cpp
)

target_link_libraries(simple_graphics_sfml
    ${SFML_LIBRARIES}
)

add_executable(simple_opengl_sfml
    simple_opengl_sfml.cpp
)

target_link_libraries(simple_opengl_sfml
    ${SFML_LIBRARIES}
    ${OPENGL_LIBRARIES}
)
