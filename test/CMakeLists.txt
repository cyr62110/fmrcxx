cmake_minimum_required(VERSION 3.5)

set(SOURCES
	main.cpp
	IteratorTest.cpp
	RangeTest.cpp
	StdIterator.cpp)
	
include_directories(../include)
add_executable(testLibrary ${SOURCES})
target_link_libraries(testLibrary fmrcxx)