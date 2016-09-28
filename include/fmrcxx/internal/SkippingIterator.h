#ifndef FMRCXX_INTERNAL_SKIPPINGITERATOR_H_
#define FMRCXX_INTERNAL_SKIPPINGITERATOR_H_

#include <cstdint>

#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will skip the first n item from the preceding iterator.
 * \tparam T Type of item in iterator on which we will apply the transformation
 * \tparam It It Type of the iterator on which we will apply the transformation
 *
 * ## Memory model
 *
 * This transformation will not claim the ownership of ANY item.
 *
 */
template <typename T, typename It>
class SkippingIterator : TransformingIterator<T, It, SkippingIterator<T, It>> {
public:
	SkippingIterator(std::uint32_t skip, It&& iterator);

	SkippingIterator(SkippingIterator&& rhs);
private:
	T* doComputeNext();

	std::uint32_t current;
	std::uint32_t skip;
};

}}

#endif
