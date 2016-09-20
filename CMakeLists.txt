cmake_minimum_required(VERSION 3.5)
project ("FMRCXX library" CXX)

# Project written in C++11
set (CMAKE_CXX_STANDARD 11)

# Output directories
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(test)

add_library(fmrcxx STATIC src/main.cpp)