#include "../catch.hpp"

#include "../util/LightTestObject.h"
#include "../util/NoMoveTestObject.h"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/MappingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "check doComputeNext in static MappingIterator", "[MappingIterator]" ) {
	Range<int> range1(1, 5);
	MappingIterator<std::string, int, Range<int>, false> it([](int& elt) {
		return std::to_string(elt);
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == "1" );
}

TEST_CASE ("check number of times constructor and destructor are called in static MappingIterator", "[MappingIterator]") {
	LightTestObject::resetCounters();

	Range<int> range1(1, 5);
	MappingIterator<int, int, Range<int>, false> it([](int& elt) {
		return elt * 2;
	}, std::move(range1)); // FIXME: forEach to iterate over every single item

	REQUIRE ( LightTestObject::nbTimeConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeCopyConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeDestructorCalled == 9 );
}

TEST_CASE ("check doComputeNext in static MappingIterator uses copy iterator if move is not available", "[MappingIterator]") {
	Range<int> range1(1, 5);
	MappingIterator<NoMoveTestObject, int, Range<int>, false> it([](int& elt) {
		NoMoveTestObject o(elt);
		return o;
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 2 );
}

TEST_CASE( "check doComputeNext in dynamic MappingIterator", "[MappingIterator]" ) {
	Range<int> range1(1, 5);
	MappingIterator<std::string, int, Range<int>, true> it([](int& elt) {
		return new std::string(std::to_string(elt));
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == "1" );
}

TEST_CASE ("check number of times constructor and destructor are called in dynamic MappingIterator", "[MappingIterator]") {
	LightTestObject::resetCounters();

	Range<int> range1(1, 5);
	MappingIterator<int, int, Range<int>, false> it([](int& elt) {
		return elt * 2;
	}, std::move(range1)); // FIXME: forEach to iterate over every single item

	REQUIRE ( LightTestObject::nbTimeConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeCopyConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeDestructorCalled == 4 );
}

