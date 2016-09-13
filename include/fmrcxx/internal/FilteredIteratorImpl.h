#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_H_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_H_

#include <functional>

#include <fmrcxx/Iterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \internal
 */
template <typename T, typename It>
class FilteredIteratorImpl {
public:
	/**
	 * \brief Construct an iterator
	 * \param filterFunction function that should return true for each element that must be kept.
	 * \param iterator Iterator that will be filtered
	 */
	FilteredIteratorImpl(std::function<bool(const T&)> filterFunction, It&& iterator);

	/**
	 * Move constructor
	 */
	FilteredIteratorImpl(FilteredIteratorImpl&& rhs);

	bool fullyConsumed();
	T& next();

private:
	It iterator;
	std::function<bool(const T&)> filterFunction;
};

}}

#include "FilteredIteratorImpl.hpp"

#endif
