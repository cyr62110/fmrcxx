#include "../catch.hpp"

#include <fmrcxx/internal/TypeUtils.h>

using namespace fmrcxx;
using namespace fmrcxx::internal;

TEST_CASE( "check can convert any reference or pointer to reference", "[TypeUtils]" ) {
	int value = 42;
	int& rValue = value;
	int&& lValue = std::move(value);
	int* pValue = &value;

	int& rv1 = TypeUtils<int>::toReference(value);
	int& rv2 = TypeUtils<int&>::toReference(rValue);
	int& rv3 = TypeUtils<int*>::toReference(pValue);
	int& rv4 = TypeUtils<int&&>::toReference(lValue);

	REQUIRE( rv1 == value );
	REQUIRE( rv2 == value );
	REQUIRE( rv3 == value );
	REQUIRE( rv4 == value );
}
