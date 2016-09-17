#include "catch.hpp"

#include <fmrcxx/Range.h>

using namespace fmrcxx;

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

