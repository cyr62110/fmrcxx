#include "catch.hpp"

#include <fmrcxx/fmrcxx.h>

using namespace fmrcxx;

TEST_CASE( "check iterateOver on all standard container", "[fmrcxx]" ) {
	std::vector<int> vector {1};
	auto itVector = iterateOver(vector);
	REQUIRE( itVector.next() == 1 );


}
