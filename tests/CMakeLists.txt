cmake_minimum_required(VERSION 4.0)
project(KerionGL-Tests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TESTS
        test_version.cpp
)

add_executable(KerionGL-Tests test_version.cpp)
target_include_directories(KerionGL-Tests PRIVATE ${CMAKE_SOURCE_DIR}/include)


foreach(t ${TESTS})
    get_filename_component(name ${t} NAME_WE)
    add_executable(${name} ${t})
    target_include_directories(${name} PRIVATE ${CMAKE_SOURCE_DIR}/include)
    add_test(NAME ${name} COMMAND ${name})
endforeach()

