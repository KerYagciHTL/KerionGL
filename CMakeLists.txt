cmake_minimum_required(VERSION 4.0)
project(KerionGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(tests)

add_executable(KerionGL src/main.cpp)

target_include_directories(KerionGL PRIVATE include)
