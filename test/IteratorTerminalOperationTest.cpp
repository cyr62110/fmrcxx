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

