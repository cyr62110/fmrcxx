cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_FMRCXX_TESTING") # Allow us to test private methods

set(SOURCES
	main.cpp
	SummaryStatsTest.cpp
	IteratorTest.cpp
	FmrcxxTest.cpp
	RangeTest.cpp
	IteratorTerminalOperationTest.cpp
	IteratorMapTerminalOperationTest.cpp
	IteratorArithmeticTerminalOperationTest.cpp
	IteratorTransformingOperationTest.cpp
	internal/StdContainerIteratorTest.cpp
	internal/StdMapIteratorTest.cpp
	internal/TransformingIteratorTest.cpp
	internal/FilteredIteratorTest.cpp
	internal/MappingIteratorTest.cpp
	internal/LimitingIteratorTest.cpp
	internal/SkippingIteratorTest.cpp
	
set(UTIL_SOURCES
	util/LightTestObject.cpp
	util/NoMoveTestObject.cpp)
	
include_directories(../include)
add_executable(testLibrary ${SOURCES} ${UTIL_SOURCES})
target_link_libraries(testLibrary fmrcxx)