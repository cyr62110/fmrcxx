#include "../catch.hpp"

#include <vector>
#include <fmrcxx/fmrcxx.h>

#include "../util/LightTestObject.h"

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "check doComputeNext in CopyingIterator", "[CopyingIterator]" ) {
	std::vector<std::string> strs;
	strs.emplace_back("Hello");

	StdContainerIterator<std::string, std::vector<std::string>::iterator> baseIt = fmrcxx::iterateOver(strs);
	auto it = CopyingIterator<std::string, StdContainerIterator<std::string, std::vector<std::string>::iterator>>(std::move(baseIt));

	std::string& first = it.next();
	REQUIRE ( first == "Hello" );
	REQUIRE ( &first != &strs[0] );

	REQUIRE ( it.fullyConsumed() );
}

TEST_CASE( "check number times constructor & destructor called in CopyingIterator if iterator does not own items.", "[CopyingIterator]" ) {
	std::vector<LightTestObject> objs;
	objs.emplace_back(1);
	objs.emplace_back(2);

	StdContainerIterator<LightTestObject, std::vector<LightTestObject>::iterator> baseIt = fmrcxx::iterateOver(objs);
	auto it = CopyingIterator<LightTestObject, StdContainerIterator<LightTestObject, std::vector<LightTestObject>::iterator>>(std::move(baseIt));

	LightTestObject::resetCounters();

	while (!it.fullyConsumed()) {
		it.next();
	}

	REQUIRE( LightTestObject::nbTimeConstructorCalled == 0 );
	REQUIRE( LightTestObject::nbTimeCopyConstructorCalled == 2 );
	REQUIRE( LightTestObject::nbTimeMoveConstructorCalled == 0 );
	REQUIRE( LightTestObject::nbTimeDestructorCalled == 1 );
}

TEST_CASE( "check number times constructor & destructor called in CopyingIterator if iterator owns items.", "[CopyingIterator]" ) {
	LightTestObject::resetCounters();

	auto it = Range<int>(1, 2).map<LightTestObject>([](int& elt) {
		return new LightTestObject(elt);
	}).copy();

	while (!it.fullyConsumed()) {
		it.next();
	}

	REQUIRE( LightTestObject::nbTimeConstructorCalled == 2 );
	REQUIRE( LightTestObject::nbTimeCopyConstructorCalled == 0 );
	REQUIRE( LightTestObject::nbTimeMoveConstructorCalled == 0 );
	REQUIRE( LightTestObject::nbTimeDestructorCalled == 1 );
}
