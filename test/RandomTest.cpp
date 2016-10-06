#include "catch.hpp"

#include <fmrcxx/Random.h>

using namespace fmrcxx;

TEST_CASE( "check move construct random", "[Random]" ) {
	Random<int> rng(1, 5);
	Random<int> rng2(std::move(rng));

	REQUIRE_FALSE( rng.fullyConsumed() );
}

TEST_CASE( "check random generate integer within range", "[Random]" ) {
	Random<int> rng(1, 5);

	int next = rng.next();
	REQUIRE( next >= 1 );
	REQUIRE( next <= 5 );
}

TEST_CASE( "check random generate double within range", "[Random]" ) {
	Random<double> rng(0, 1);

	double next = rng.next();
	REQUIRE( next >= 0 );
	REQUIRE( next <= 1 );
}
