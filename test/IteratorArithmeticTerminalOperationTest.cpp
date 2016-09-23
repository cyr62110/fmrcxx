#include "catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/exception/OperationOnFullyConsumedIteratorException.h>

using namespace fmrcxx;

TEST_CASE( "check sum", "[IteratorArithmeticTerminalOperation]" ) {
	Range<int> range(1, 5);
	REQUIRE( range.sum() == 15 );
}

TEST_CASE( "check min", "[IteratorArithmeticTerminalOperation]" ) {
	Range<int> range(1, 5);
	REQUIRE( range.min() == 1 );

	Range<int> emptyRange (1, 0);
	REQUIRE_THROWS_AS( range.min(), exception::OperationOnFullyConsumedIteratorException );
}

TEST_CASE( "check max", "[IteratorArithmeticTerminalOperation]" ) {
	Range<int> range(1, 5);
	REQUIRE( range.max() == 5 );

	Range<int> emptyRange (1, 0);
	REQUIRE_THROWS_AS( range.max(), exception::OperationOnFullyConsumedIteratorException );
}

TEST_CASE( "check average", "[IteratorArithmeticTerminalOperation]" ) {
	Range<int> range(1, 5);
	double avg = range.average();
	REQUIRE( avg >= 2.99999 );
	REQUIRE( avg <= 3.00001 );

	Range<int> emptyRange (1, 0);
	REQUIRE_THROWS_AS( range.average(), exception::OperationOnFullyConsumedIteratorException );
}


