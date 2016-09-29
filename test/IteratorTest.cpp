#include "catch.hpp"

#include <fmrcxx/Iterator.h>
#include <fmrcxx/Range.h>

using namespace fmrcxx;

TEST_CASE( "Will forward memory ownership attributes", "[Iterator]" ) {
	Iterator<int, Range<int>> it(1, 5);

	REQUIRE( it.ownItem() );
	REQUIRE_FALSE( it.areItemAllocatedDynamically() );
}

TEST_CASE( "Moved iterator return false for all memory ownership attributes", "[Iterator]" ) {
	Iterator<int, Range<int>> it(1, 5);
	Iterator<int, Range<int>> it1(std::move(it));

	REQUIRE( it1.ownItem() );
	REQUIRE_FALSE( it1.areItemAllocatedDynamically() );

	REQUIRE_FALSE( it.ownItem() );
	REQUIRE_FALSE( it.areItemAllocatedDynamically() );
}

TEST_CASE( "Can chain iterator operation", "[Iterator]" ) {
	Range<int> range(1, 5);

	const auto& it = range.filter([](const int& value) {
			return (value & 1) == 0;
		}).filter([](const int& value) {
			return (value % 2) == 0;
		});
}
