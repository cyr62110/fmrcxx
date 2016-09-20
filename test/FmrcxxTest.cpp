#include "catch.hpp"

#include <vector>
#include <map>

#include <fmrcxx/fmrcxx.h>

using namespace fmrcxx;

TEST_CASE( "check iterateOver on all standard container", "[fmrcxx]" ) {
	std::vector<int> vector {1};
	auto itVector = iterateOver(vector);
	REQUIRE( itVector.next() == 1 );

}

TEST_CASE( "check iterateOverMap on all standard container", "[fmrcxx]" ) {
	std::map<std::string, std::string> map;
	map["hello"] = "world";

	auto itMap = iterateOverMap(map);
	REQUIRE( itMap.next().getKey() == "hello" );

}
