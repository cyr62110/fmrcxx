#ifndef FMRCXX_INTERNAL_IMPL_LIMITINGITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_LIMITINGITERATOR_HPP_

#include <fmrcxx/internal/LimitingIterator.h>
#include <iostream>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
LimitingIterator<T, It>::LimitingIterator(std::uint32_t limit, It&& iterator) :
	TransformingIterator<T, It, LimitingIterator<T, It>>(std::move(iterator)),
	limit(limit),
	current(0) {
}

template <typename T, typename It>
LimitingIterator<T, It>::LimitingIterator(LimitingIterator<T, It>&& rhs) :
	TransformingIterator<T, It, LimitingIterator<T, It>>(std::move(rhs)),
	limit(rhs.limit),
	current(rhs.current) {
}

template <typename T, typename It>
T* LimitingIterator<T, It>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	if (this->current >= this->limit) {
		return nullptr;
	}
	this->current ++;
	return &this->iterator.next();
}

}}

#endif
