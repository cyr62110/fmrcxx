#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_H_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_H_

#include <functional>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming that will filter item according to the result of a function.
 * \tparam T Type of item in iterator on which we will apply the transformation
 * \tparam It It Type of the iterator on which we will apply the transformation
 *
 * ## Memory model
 *
 * This transformation will not claim the ownership of ANY item.
 *
 */
template <typename T, typename It>
class FilteredIterator : FMRCXX_PRIVATE TransformingIterator<T, It, FilteredIterator<T, It>> {
public:
	/**
	 * \brief Construct an iterator
	 * \param filterFunction function that should return true for each element that must be kept.
	 * \param iterator Iterator that will be filtered
	 */
	FilteredIterator(std::function<bool(const T&)> filterFunction, It&& iterator);

	/**
	 * Move constructor
	 */
	FilteredIterator(FilteredIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	std::function<bool(const T&)> filterFunction;
};

}}

#include <fmrcxx/internal/impl/FilteredIterator.hpp>

#endif
