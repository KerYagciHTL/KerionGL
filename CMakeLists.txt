cmake_minimum_required(VERSION 4.0)
project(KerionGL)

set(CMAKE_CXX_STANDARD 20)

add_executable(KerionGL src/main.cpp)

target_include_directories(KerionGL PRIVATE include)
