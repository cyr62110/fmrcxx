cmake_minimum_required(VERSION 2.8)

set(SOURCES
	main.cpp
	pi.cpp)
	
include_directories(../include)
add_executable(examples ${SOURCES})
target_link_libraries(examples fmrcxx)