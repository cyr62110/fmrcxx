cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} 
	-D_FMRCXX_TESTING # Allow us to test private methods
	)

set(SOURCES
	main.cpp
	IteratorTest.cpp
	RangeTest.cpp
	StdIterator.cpp
	internal/TransformingIteratorTest.cpp
	internal/FilteredIteratorTest.cpp
	internal/MappingIteratorTest.cpp)
	
include_directories(../include)
add_executable(testLibrary ${SOURCES})
target_link_libraries(testLibrary fmrcxx)