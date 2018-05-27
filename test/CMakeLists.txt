cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_FLAGS “--gmock_verbose=info“)
set(CMAKE_CXX_STANDARD 11)

add_executable(hello_test helloTest.cpp)

target_link_libraries(hello_test gtest gtest_main gmock)
