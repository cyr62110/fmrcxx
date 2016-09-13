#ifndef FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_
#define FMRCXX_INTERNAL_FILTEREDITERATOR_HPP_

#include <fmrcxx/internal/FilteredIteratorImpl.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
FilteredIteratorImpl<T, It>::FilteredIteratorImpl(std::function<bool(const T&)> filterFunction, It&& iterator) :
	filterFunction(std::move(filterFunction)),
	iterator(std::move(iterator)) {
}

template <typename T, typename It>
FilteredIteratorImpl<T, It>::FilteredIteratorImpl(FilteredIteratorImpl<T, It>&& rhs) :
	filterFunction(std::move(rhs.filterFunction)),
	iterator(std::move(rhs.iterator)) {
}

}}

#endif
