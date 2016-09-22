#include "catch.hpp"

#include <fmrcxx/SummaryStats.h>

using namespace fmrcxx;

TEST_CASE( "Check basic statistics method", "[SummaryStats]" ) {
	SummaryStats<int> stats;
	stats.accumulate(4);
	stats.accumulate(10);
	stats.accumulate(2);
	stats.accumulate(8);
	stats.accumulate(6);

	REQUIRE( stats.getCount() == 5 );
	REQUIRE( stats.getMin() == 2 );
	REQUIRE( stats.getMax() == 10 );
	REQUIRE( stats.getSum() == 30 );
	REQUIRE( stats.getAverage() > 5.999 );
	REQUIRE( stats.getAverage() < 6.001 );
}
