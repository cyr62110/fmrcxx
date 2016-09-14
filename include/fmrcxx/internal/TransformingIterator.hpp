#ifndef FMRCXX_INTERNAL_TRANSFORMINGITERATOR_HPP_
#define FMRCXX_INTERNAL_TRANSFORMINGITERATOR_HPP_

#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {

template <typename T, typename It>
TransformingIterator<T, It>::TransformingIterator() :
	moved(false),
	computedNext(nullptr),
	isNextComputed(false) {
}

template <typename T, typename It>
TransformingIterator<T, It>::TransformingIterator(TransformingIterator&& rhs) :
	moved(false),
	computedNext(rhs.computedNext),
	isNextComputed(rhs.isNextComputed) {
	rhs.moved = true;
}

template <typename T, typename It>
bool TransformingIterator<T, It>::fullyConsumed() {
	if (this->moved) {
		return true;
	}
	return this->computeNext() != nullptr;
}

template <typename T, typename It>
T& TransformingIterator<T, It>::next() {
	if (this->fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	const T* current = computeNext();
	this->isNextComputed = false;
	return *current;
}

template <typename T, typename It>
const T* TransformingIterator<T, It>::computeNext() {
	if (this->isNextComputed) {
		return computedNext;
	}
	this->isNextComputed = true;
	this->computedNext = &this->doComputeNext();
	return this->computedNext;
}


}

#endif
