cmake_minimum_required(VERSION 2.8)
project ("FMRCXX library" CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11") # Project written in C++11

# Output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(test)
add_subdirectory(examples)

add_library(fmrcxx STATIC src/main.cpp)