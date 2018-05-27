cmake_minimum_required(VERSION 3.9)

project(hello)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
add_subdirectory(test)
add_subdirectory(googletest)

set(CMAKE_VERBOSE_MAKEFILE ON)



