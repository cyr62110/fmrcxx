#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/TransformingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "TransformingIteratorTest fullyConsumed", "[TransformingIteratorTest]" ) {
	Range<int> range1(1, 5);
	FilteredIterator<int, Range<int>> it1([](const int& elt) {
		return elt % 2 == 0;
	}, std::move(range1));
	REQUIRE_FALSE( it1.fullyConsumed() );

	Range<int> range2(1, 5);
	FilteredIterator<int, Range<int>> it2([](const int& elt) {
		return elt == 6;
	}, std::move(range2));
	REQUIRE( it2.fullyConsumed() );
}

TEST_CASE( "TransformingIteratorTest next", "[TransformingIteratorTest]" ) {
	Range<int> range(1, 5);
	FilteredIterator<int, Range<int>> it([](const int& elt) {
		return elt % 2 == 0;
	}, std::move(range));
	REQUIRE( it.next() == 2 );
}
