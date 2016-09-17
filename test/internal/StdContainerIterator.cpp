#include <fmrcxx/internal/StdContainerIterator.h>

#include "../catch.hpp"

#include <vector>

using namespace fmrcxx;

TEST_CASE( "check fullyConsumed in StdContainerIterator", "[StdContainerIterator]" ) {
	std::vector<std::string> vector {"hello"};
	std::vector<std::string> emptyVector;

	StdContainerIterator<std::string, std::vector<std::string>::iterator> it(vector.begin(), vector.end());
	REQUIRE_FALSE ( it.fullyConsumed() );

	StdContainerIterator<std::string, std::vector<std::string>::iterator> it2(vector.begin(), vector.end());
	it2.next();
	REQUIRE ( it2.fullyConsumed() );

	StdContainerIterator<std::string, std::vector<std::string>::iterator> it3(emptyVector.begin(), emptyVector.end());
	REQUIRE ( it3.fullyConsumed() );
}

TEST_CASE( "check next in StdContainerIterator", "[StdIterator]" ) {
	std::vector<std::string> vector {"hello", "world"};

	StdContainerIterator<std::string, std::vector<std::string>::iterator> it(vector.begin(), vector.end());
	REQUIRE ( it.next() == "hello" );
	REQUIRE ( it.next() == "world" );
}


