#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/SkippingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "SkippingIterator doComputeNext", "[SkippingIterator]" ) {
	Range<int> range1(1, 5);
	LimitingIterator<int, Range<int>> it(2, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 3 );

	Range<int> range2(1, 5);
	LimitingIterator<int, Range<int>> it2(5, std::move(range2));
	REQUIRE( it2.doComputeNext() == nullptr );
}
