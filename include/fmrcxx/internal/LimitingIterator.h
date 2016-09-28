#ifndef FMRCXX_INTERNAL_LIMITINGITERATOR_H_
#define FMRCXX_INTERNAL_LIMITINGITERATOR_H_

#include <cstdint>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will limit the number of item that will return the iterator
 * \tparam T Type of item in iterator on which we will apply the transformation
 * \tparam It It Type of the iterator on which we will apply the transformation
 *
 * ## Memory model
 *
 * This transformation will not claim the ownership of ANY item.
 *
 */
template <typename T, typename It>
class LimitingIterator : public TransformingIterator<T, It, LimitingIterator<T, It>> {
public:
	/**
	 * \brief Construct the transforming iterator
	 * \param limit Number of items that the iterator will contains at most.
	 * \param iterator Iterator that will be limited.
	 */
	LimitingIterator(std::uint32_t limit, It&& iterator);

	/**
	 * \brief Move constructor
	 */
	LimitingIterator(LimitingIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	std::uint32_t current;
	std::uint32_t limit;
};

}}

#include <fmrcxx/internal/impl/LimitingIterator.hpp>

#endif
