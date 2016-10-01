#ifndef FMRCXX_INTERNAL_IMPL_EACHINGITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_EACHINGITERATOR_HPP_

#include <fmrcxx/internal/EachingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
EachingIterator<T, It>::EachingIterator(std::function<void(T&)> eachFunction, It&& iterator) :
	TransformingIterator<T, It, EachingIterator<T, It>>(std::move(iterator)),
	eachFunction(std::move(eachFunction)) {
}

template <typename T, typename It>
EachingIterator<T, It>::EachingIterator(EachingIterator<T, It>&& rhs) :
	TransformingIterator<T, It, EachingIterator<T, It>>(std::move(rhs)),
	eachFunction(std::move(rhs.eachFunction)) {
}

template <typename T, typename It>
T* EachingIterator<T, It>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	T* computedNext = &this->iterator.next();
	this->eachFunction(*computedNext);
	return computedNext;
}

}}

#endif
