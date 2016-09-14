#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_

#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>
#include <fmrcxx/internal/FilteredIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
FilteredIterator<T, It>::FilteredIterator(std::function<bool(const T&)> filterFunction, It&& iterator) :
	TransformingIterator(iterator),
	filterFunction(std::move(filterFunction)) {
}

template <typename T, typename It>
FilteredIterator<T, It>::FilteredIterator(FilteredIterator<T, It>&& rhs) :
	TransformingIterator(rhs),
	filterFunction(std::move(rhs.filterFunction)) {
}

template <typename T, typename It>
const T& FilteredIterator<T, It>::doComputeNext() {

}

}}

#endif
