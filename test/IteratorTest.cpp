#include "catch.hpp"

#include <fmrcxx/Iterator.h>
#include <fmrcxx/Range.h>

using namespace fmrcxx;

TEST_CASE( "Can chain iterator operation", "[Iterator]" ) {
	Range<int> range(1, 5);

	const auto& it = range.filter([](const int& value) {
			return (value & 1) == 0;
		}).filter([](const int& value) {
			return (value % 2) == 0;
		});
}
