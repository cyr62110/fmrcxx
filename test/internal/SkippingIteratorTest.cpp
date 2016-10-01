#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/SkippingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "SkippingIterator doComputeNext", "[SkippingIterator]" ) {
	Range<int> range1(1, 3);
	SkippingIterator<int, Range<int>> it(2, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 3 );
	REQUIRE( it.doComputeNext() == nullptr );

	Range<int> range2(1, 5);
	SkippingIterator<int, Range<int>> it2(5, std::move(range2));
	REQUIRE( it2.doComputeNext() == nullptr );
}
