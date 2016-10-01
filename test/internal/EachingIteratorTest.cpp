#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/EachingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "EachingIterator doComputeNext", "[EachingIterator]" ) {
	int nb = 1;
	Range<int> range1(1, 2);
	EachingIterator<int, Range<int>> it([&nb](int& elt) {
		REQUIRE (elt == nb);
		nb ++;
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 1 );
	REQUIRE( *(it.doComputeNext()) == 2 );
	REQUIRE( it.doComputeNext() == nullptr );
}
