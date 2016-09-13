#include "catch.hpp"

#include <vector>
#include <fmrcxx/StdIterator.h>

using namespace fmrcxx;

TEST_CASE( "StdIterator fullyConsumed", "[StdIterator]" ) {
	std::vector<std::string> vector {"hello"};
	std::vector<std::string> emptyVector;

	StdIterator<std::string, std::vector<std::string>::iterator> it(vector.begin(), vector.end());
	REQUIRE_FALSE ( it.fullyConsumed() );

	StdIterator<std::string, std::vector<std::string>::iterator> it2(vector.begin(), vector.end());
	it2.next();
	REQUIRE ( it2.fullyConsumed() );

	StdIterator<std::string, std::vector<std::string>::iterator> it3(emptyVector.begin(), emptyVector.end());
	REQUIRE ( it3.fullyConsumed() );
}

TEST_CASE( "StdIterator next", "[StdIterator]" ) {
	std::vector<std::string> vector {"hello", "world"};

	StdIterator<std::string, std::vector<std::string>::iterator> it(vector.begin(), vector.end());
	REQUIRE ( it.next() == "hello" );
	REQUIRE ( it.next() == "world" );
}


