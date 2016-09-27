#ifndef FMRCXX_INTERNAL_IMPL_SKIPPINGITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_SKIPPINGITERATOR_HPP_

#include <fmrcxx/internal/SkippingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
SkippingIterator<T, It>::SkippingIterator(std::uint32_t skip, It&& iterator) :
	TransformingIterator<T, It, SkippingIterator<T, It>>(std::move(iterator)),
	skip(skip),
	current(0) {
}

template <typename T, typename It>
SkippingIterator<T, It>::SkippingIterator(SkippingIterator<T,It>&& rhs) :
	TransformingIterator<T, It, SkippingIterator<T, It>>(std::move(rhs)),
	skip(rhs.skip),
	current(0) {
}

template <typename T, typename It>
T* SkippingIterator<T, It>::doComputeNext() {
	while (this->current < this->skip && !this->iterator.fullyConsumed()) {
		this->iterator.next();
		this->current ++;
	}
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	return &this->iterator.next();
}

}}
