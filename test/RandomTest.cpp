#include "catch.hpp"

#include <fmrcxx/Random.h>

using namespace fmrcxx;

TEST_CASE( "check two random have same output if seeds are different", "[Random]" ) {
	Random<int> rng1(1);
	Random<int> rng2(1);

	REQUIRE ( rng1.next() == rng2.next() );
}

TEST_CASE( "check two random have different output if seeds are different", "[Random]" ) {
	Random<int> rng1(1);
	Random<int> rng2(2);

	REQUIRE ( rng1.next() != rng2.next() );
}

TEST_CASE( "check move construct random", "[Random]" ) {
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

	Random<int> rng(seed, 1, 5);
	Random<int> rng2(std::move(rng));

	REQUIRE_FALSE( rng.fullyConsumed() );
}

TEST_CASE( "check random generate integer within range", "[Random]" ) {
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

	Random<int> rng(seed, 1, 5);

	int next = rng.next();
	REQUIRE( next >= 1 );
	REQUIRE( next <= 5 );
}

TEST_CASE( "check random generate double within range", "[Random]" ) {
	unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();

	Random<double> rng(seed, 0, 1);

	double next = rng.next();
	REQUIRE( next >= 0 );
	REQUIRE( next <= 1 );
}
