#include "catch.hpp"

#include <fmrcxx/Range.h>

using namespace fmrcxx;

TEST_CASE( "Range fullyConsumed", "[Range]" ) {
	Range<int> range(1, 1);
	REQUIRE_FALSE ( range.fullyConsumed() );

	Range<int> range2(1, 2);
	range2.next();
	REQUIRE_FALSE ( range2.fullyConsumed() );

	Range<int> range3(1, 0);
	REQUIRE ( range3.fullyConsumed() );

	Range<int> range4(1, 1);
	Range<int> range5(std::move(range4));
	REQUIRE ( range4.fullyConsumed() );
}

TEST_CASE( "Range next", "[Range]" ) {
	Range<int> range(1, 5);

	REQUIRE ( range.next() == 1 );
	REQUIRE ( range.next() == 2 );
	REQUIRE ( range.next() == 3 );
	REQUIRE ( range.next() == 4 );
	REQUIRE ( range.next() == 5 );
}

TEST_CASE ("Range filter", "[Range]") {
	Range<int> range(1, 5);

	const auto& it = range.filter([](const int& value) {
		return value % 2;
	});
}
