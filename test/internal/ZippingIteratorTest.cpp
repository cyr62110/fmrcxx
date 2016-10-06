#include "../catch.hpp"

#include <fmrcxx/internal/ZippingIterator.h>
#include <fmrcxx/Range.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "ZippingIterator doComputeNext", "[ZippingIterator]" ) {
	Range<int> range1(1, 2);
	Range<int> range2(2, 1, -1);

	ZippingIterator<int, Range<int>, int, Range<int>> it = ZippingIterator<int, Range<int>, int, Range<int>>(std::move(range1), std::move(range2));

	Tuple<int&, int&>* t = it.doComputeNext();
	REQUIRE ( t->getKey() == 1 );
	REQUIRE ( t->getValue() == 2 );

	t = it.doComputeNext();
	REQUIRE ( t->getKey() == 2 );
	REQUIRE ( t->getValue() == 1 );

	t = it.doComputeNext();
	REQUIRE ( t == nullptr );
}
