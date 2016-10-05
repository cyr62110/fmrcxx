#include "catch.hpp"

#include "util/LightTestObject.h"

#include <fmrcxx/fmrcxx.h>

using namespace fmrcxx;

TEST_CASE( "check toMap with std::map", "[IteratorMapTerminalOperation]" ) {
	LightTestObject::resetCounters();

	std::map<std::string, int> map;
	map["hello"] = 1;
	map["world"] = 2;

	std::map<std::string, LightTestObject> items = iterateOverMap(map)
			.map<Tuple<std::string, LightTestObject>>([](Tuple<const std::string&, int&> value) {
				return Tuple<std::string, LightTestObject>(value.getKey(), LightTestObject(value.getValue()));
			})
			.toMap<std::map>();

	REQUIRE ( (*items.find("hello")).second.getValue() == 1 );
	REQUIRE ( (*items.find("world")).second.getValue() == 2 );
	REQUIRE ( items.size() == 2 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled >= 2 );
}

TEST_CASE( "check copy to map with std::map using raw pointer", "[IteratorMapTerminalOperation]" ) {
	std::map<std::string, LightTestObject> map;
	map.emplace("hello", 1);
	map.emplace("world", 2);

	LightTestObject::resetCounters();

	auto items = iterateOverMap(map)
			.copyToMap<std::map>();

	REQUIRE ( (*items.find("hello")).second->getValue() == 1 );
	REQUIRE ( (*items.find("hello")).second != &(*map.find("hello")).second );
	REQUIRE ( items.size() == 2 );
	REQUIRE ( LightTestObject::nbTimeCopyConstructorCalled == 2 );
	REQUIRE ( LightTestObject::nbTimeMoveConstructorCalled == 0 );
	REQUIRE ( LightTestObject::nbTimeDestructorCalled == 0 );

	for (auto it = items.begin(); it != items.end(); it++) {
		delete it->second;
	}
}

/* FIXME Not working
TEST_CASE( "check copy to map with std::map using unique pointer", "[IteratorMapTerminalOperation]" ) {
	std::map<std::string, LightTestObject> map;
	map.emplace("hello", 1);
	map.emplace("world", 2);

	LightTestObject::resetCounters();

	auto items = std::move(iterateOverMap(map)
			.copyToMap<std::map, std::unique_ptr<LightTestObject>>());

	REQUIRE ( (*items.find("hello")).second->getValue() == 1 );
	REQUIRE ( items.size() == 2 );
}
*/

