#ifndef FMRCXX_INTERNAL_MAPPINGITERATOR_HPP_
#define FMRCXX_INTERNAL_MAPPINGITERATOR_HPP_

#include <fmrcxx/internal/MappingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename I, typename It>
MappingIterator<T, I, It>::MappingIterator(std::function<T(I&)> mapFunction, It&& iterator) :
	TransformingIterator<T, It, MappingIterator<T, I, It>>(std::move(iterator)),
	mapFunction(std::move(mapFunction)),
	computedNextPtr() {
}

template <typename T, typename I, typename It>
MappingIterator<T, I, It>::MappingIterator(MappingIterator&& rhs) :
	TransformingIterator<T, It, MappingIterator<T, I, It>>(std::move(rhs)),
	mapFunction(std::move(rhs.mapFunction)),
	computedNextPtr() {
}

template <typename T, typename I, typename It>
T* MappingIterator<T, I, It>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	std::unique_ptr<T> ptr = std::make_unique<T>(this->mapFunction(this->iterator.next()));
	this->computedNextPtr = std::move(ptr);
	return &(*this->computedNextPtr);
}

}}

#endif
