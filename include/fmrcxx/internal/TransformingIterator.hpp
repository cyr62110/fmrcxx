#ifndef FMRCXX_INTERNAL_TRANSFORMINGITERATOR_HPP_
#define FMRCXX_INTERNAL_TRANSFORMINGITERATOR_HPP_

#include <fmrcxx/internal/TransformingIterator.h>
#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T, typename It, typename TIt>
TransformingIterator<T, It, TIt>::TransformingIterator(It&& iterator) :
	moved(false),
	iterator(std::move(iterator)),
	computedNext(nullptr),
	isNextComputed(false) {
}

template <typename T, typename It, typename TIt>
TransformingIterator<T, It, TIt>::TransformingIterator(TransformingIterator&& rhs) :
	moved(false),
	iterator(std::move(rhs.iterator)),
	computedNext(rhs.computedNext),
	isNextComputed(rhs.isNextComputed) {
	rhs.moved = true;
}

template <typename T, typename It, typename TIt>
bool TransformingIterator<T, It, TIt>::fullyConsumed() {
	if (this->moved) {
		return true;
	}
	return this->computeNext() == nullptr;
}

template <typename T, typename It, typename TIt>
T& TransformingIterator<T, It, TIt>::next() {
	if (this->fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	T* current = computeNext();
	this->isNextComputed = false;
	return *current;
}

template <typename T, typename It, typename TIt>
T* TransformingIterator<T, It, TIt>::computeNext() {
	if (this->isNextComputed) {
		return this->computedNext;
	}
	this->isNextComputed = true;
	this->computedNext = ((TIt*)this)->doComputeNext();
	return this->computedNext;
}


}

#endif
