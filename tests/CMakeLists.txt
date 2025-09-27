cmake_minimum_required(VERSION 4.0)
project(KerionGL-Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TESTS
        test_version.cpp
        test_window.cpp
)

foreach(t ${TESTS})
    get_filename_component(name ${t} NAME_WE)
    add_executable(${name} ${t})
    target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include vendor/glfw/include)
    target_link_libraries(${name} PRIVATE KerionGL_lib glfw)
    add_test(NAME ${name} COMMAND ${name})
endforeach()
