#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/FilteredIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "FilteredIterator doComputeNext", "[FilteredIterator]" ) {
	Range<int> range1(1, 5);
	FilteredIterator<int, Range<int>> it([](const int& elt) {
		return elt % 2 == 0;
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 2 );
}
