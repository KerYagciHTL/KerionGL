cmake_minimum_required(VERSION 4.0.2)
project(KerionGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

find_package(OpenGL REQUIRED)

add_library(KerionGL_lib STATIC
        src/window.cpp
        include/keriongl/window.h
        include/keriongl/shape.h
        include/keriongl/color.h
)
target_include_directories(KerionGL_lib PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)
target_link_libraries(KerionGL_lib PUBLIC
        glfw
        OpenGL::GL
)

add_executable(KerionGL
        src/main.cpp
        src/rectangle.cpp
        src/triangle.cpp
)
target_link_libraries(KerionGL PRIVATE KerionGL_lib)

enable_testing()
add_subdirectory(tests)
