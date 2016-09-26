#include "catch.hpp"

#include <list>

#include <fmrcxx/Range.h>
#include <fmrcxx/exception/UnsupportedContainerTypeException.h>

#include "util/LightTestObject.h"

using namespace fmrcxx;

TEST_CASE( "check count", "[IteratorTerminalOperation]" ) {
	Range<int> range(1, 5);
	REQUIRE( range.count() == 5 );
}

TEST_CASE( "check forEach", "[IteratorTerminalOperation]" ) {
	int sum = 0;
	Range<int> range(1, 5);

	range.forEach([&sum](int& elt) {
		sum += elt;
	});

	REQUIRE( sum == 15 );
}

TEST_CASE( "check reduce with Acc", "[IteratorTerminalOperation]" ) {
	int sum = Range<int>(1, 5).reduce<int>(0, [](int& acc, const int& elt) {
		return acc + elt;
	});

	REQUIRE ( sum == 15 );
}

TEST_CASE( "check reduce with Acc&", "[IteratorTerminalOperation]" ) {
	int sum = 0;
	Range<int>(1, 5).reduce<int>(sum, [](int& acc, const int& elt) {
		acc += elt;
	});

	REQUIRE ( sum == 15 );
}

TEST_CASE( "check to unsupported container type", "[IteratorTerminalOperation]" ) {
	std::function<void(void)> fn = []() {
		Range<int>(1, 5).to<std::map, int>();
	};
	REQUIRE_THROWS_AS( fn(), exception::UnsupportedContainerTypeException );
}

TEST_CASE( "check to std::vector", "[IteratorTerminalOperation]" ) {
	LightTestObject::resetCounters();

	std::vector<LightTestObject> items = Range<int>(1, 5).map<LightTestObject>([](int& elt) {
		return LightTestObject(elt);
	}).to<std::vector>();

	REQUIRE( items.size() == 5 );
	REQUIRE( items[2].getValue() == 3 );
	REQUIRE( LightTestObject::nbTimeMoveConstructorCalled >= 10 );
}

