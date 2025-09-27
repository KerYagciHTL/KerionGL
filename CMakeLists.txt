cmake_minimum_required(VERSION 4.0)
project(KerionGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(tests)
add_subdirectory(vendor/glfw)

add_library(KerionGL_lib STATIC src/window.cpp)
target_include_directories(KerionGL_lib PUBLIC include vendor/glfw/include)
target_link_libraries(KerionGL_lib PUBLIC glfw)
target_link_libraries(KerionGL_lib PUBLIC GL)

add_executable(KerionGL src/main.cpp)
target_link_libraries(KerionGL PRIVATE KerionGL_lib)
