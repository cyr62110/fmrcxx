cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} 
	-D_FMRCXX_TESTING # Allow us to test private methods
	)

set(SOURCES
	main.cpp
	IteratorTest.cpp
	FmrcxxTest.cpp
	RangeTest.cpp
	IteratorTerminalOperationTest.cpp
	IteratorTransformingOperationTest.cpp
	internal/StdContainerIterator.cpp
	internal/TransformingIteratorTest.cpp
	internal/FilteredIteratorTest.cpp
	internal/MappingIteratorTest.cpp)
	
set(UTIL_SOURCES
	util/LightTestObject.cpp
	util/NoMoveTestObject.cpp)
	
include_directories(../include)
add_executable(testLibrary ${SOURCES} ${UTIL_SOURCES})
target_link_libraries(testLibrary fmrcxx)