#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/LimitingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "LimitingIterator doComputeNext", "[LimitingIterator]" ) {
	Range<int> range1(1, 5);
	LimitingIterator<int, Range<int>> it(0, std::move(range1));
	REQUIRE( it.doComputeNext() == nullptr );

	Range<int> range2(1, 5);
	LimitingIterator<int, Range<int>> it2(2, std::move(range2));
	REQUIRE( *(it2.doComputeNext()) == 1 );
	REQUIRE( *(it2.doComputeNext()) == 2 );
	REQUIRE( it2.doComputeNext() == nullptr );
}
