#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_

#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>
#include <fmrcxx/internal/FilteredIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
FilteredIterator<T, It>::FilteredIterator(std::function<bool(const T&)> filterFunction, It&& iterator) :
	TransformingIterator<T, It, FilteredIterator<T, It>>(std::move(iterator)),
	filterFunction(std::move(filterFunction)) {
}

template <typename T, typename It>
FilteredIterator<T, It>::FilteredIterator(FilteredIterator<T, It>&& rhs) :
	TransformingIterator<T, It, FilteredIterator<T, It>>(std::move(rhs)),
	filterFunction(std::move(rhs.filterFunction)) {
}

template <typename T, typename It>
T* FilteredIterator<T, It>::doComputeNext() {
	T* computedNext = nullptr;
	while (computedNext == nullptr && !this->iterator.fullyConsumed()) {
		T* current = &this->iterator.next();
		if (this->filterFunction(*current)) {
			computedNext = current;
		}
	}
	return computedNext;
}

}}

#endif
