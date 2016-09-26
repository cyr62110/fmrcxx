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
