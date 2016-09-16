#include "../catch.hpp"

#include "../util/LightTestObject.h"

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
	MappingIterator<LightTestObject, int, Range<int>, false> it([](int& elt) {
		return LightTestObject(elt);
	}, std::move(range1));

	while (!it.fullyConsumed()) it.next();

	REQUIRE ( LightTestObject::nbTimeConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeCopyConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeDestructorCalled == 9 );
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
	MappingIterator<LightTestObject, int, Range<int>, true> it([](int& elt) {
		return new LightTestObject(elt);
	}, std::move(range1));

	while (!it.fullyConsumed()) it.next();

	REQUIRE ( LightTestObject::nbTimeConstructorCalled == 5 );
	REQUIRE ( LightTestObject::nbTimeCopyConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeDestructorCalled == 4 );
}

