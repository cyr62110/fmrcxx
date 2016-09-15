#include "../catch.hpp"

#include <fmrcxx/Range.h>
#include <fmrcxx/internal/MappingIterator.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "MappingIterator doComputeNext", "[MappingIterator]" ) {
	Range<int> range1(1, 5);
	MappingIterator<int, int, Range<int>> it([](const int& elt) {
		return elt * 2;
	}, std::move(range1));
	REQUIRE( *(it.doComputeNext()) == 2 );
}


