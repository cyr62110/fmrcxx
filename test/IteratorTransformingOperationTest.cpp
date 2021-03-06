#include "catch.hpp"

#include <memory>
#include <string>

#include <fmrcxx/Range.h>

using namespace fmrcxx;

TEST_CASE( "do filter compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).filter([](const int& elt) {
		return true;
	});
}

TEST_CASE( "do static map compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).map<std::string>([](int& elt) {
		return std::to_string(elt);
	});
}

TEST_CASE( "do dynamic map compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).map<std::string>([](int& elt) {
		return new std::string(std::to_string(elt));
	});
}

TEST_CASE( "do limit compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).limit(1);
}

TEST_CASE( "do skip compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).skip(1);
}

TEST_CASE( "do each compile", "[IteratorTransformingOperation]" ) {
	Range<int>(1, 5).each([](int& elt) {});
}

TEST_CASE( "do zip compile", "[IteratorTransformingOperation]" ) {
	Range<int> range(1, 5);
	Range<int>(1, 5).zip<int>(std::move(range));
}
