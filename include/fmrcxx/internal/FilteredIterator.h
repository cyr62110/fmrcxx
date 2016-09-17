#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_H_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_H_

#include <functional>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \internal
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
