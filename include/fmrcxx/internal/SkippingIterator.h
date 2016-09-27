#ifndef FMRCXX_INTERNAL_SKIPPINGITERATOR_H_
#define FMRCXX_INTERNAL_SKIPPINGITERATOR_H_

#include <cstdint>

#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
class SkippingIterator : TransformingIterator<T, It, SkippingIterator<T, It>> {
public:
	SkippingIterator(std::uint32_t skip, It&& iterator);

	SkippingIterator(SkippingIterator&& rhs);

	// FIXME Since skip is particular operation, need to override fullyConsumed and next directly
private:
	std::uint32_t current;
	std::uint32_t skip;
};

}}

#endif