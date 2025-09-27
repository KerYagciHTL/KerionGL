cmake_minimum_required(VERSION 4.0)
project(KerionGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(tests)
add_subdirectory(vendor/glfw)

add_executable(KerionGL src/main.cpp
        src/window.cpp)

target_include_directories(KerionGL PRIVATE include)
target_include_directories(KerionGL PRIVATE vendor/glfw/include)

target_link_libraries(KerionGL PRIVATE glfw)
