#include "../catch.hpp"

#include <map>

#include <fmrcxx/internal/StdMapIterator.h>

using namespace fmrcxx;

TEST_CASE( "check fullyConsumed in StdMapIterator", "[StdMapIterator]" ) {
	std::map<std::string, std::string> map;
	map["hello"] = "world";

	std::map<std::string, std::string> emptyMap;

	StdMapIterator<std::string, std::string, std::map<std::string, std::string>::iterator> it(map.begin(), map.end());
	REQUIRE_FALSE ( it.fullyConsumed() );

	StdMapIterator<std::string, std::string, std::map<std::string, std::string>::iterator> it2(map.begin(), map.end());
	it2.next();
	REQUIRE ( it2.fullyConsumed() );

	StdMapIterator<std::string, std::string, std::map<std::string, std::string>::iterator> it3(emptyMap.begin(), emptyMap.end());
	REQUIRE ( it3.fullyConsumed() );
}

TEST_CASE( "check next in StdMapIterator", "[StdMapIterator]" ) {
	std::map<std::string, std::string> map;
	map["hello"] = "world";
	map["hello2"] = "world2";

	StdMapIterator<std::string, std::string, std::map<std::string, std::string>::iterator> it(map.begin(), map.end());
	auto& next = it.next();
	REQUIRE ( next.getKey() == "hello" );
	REQUIRE ( next.getValue() == "world" );

	auto& next2 = it.next();
	REQUIRE ( next2.getKey() == "hello2" );
	REQUIRE ( next2.getValue() == "world2" );
}
