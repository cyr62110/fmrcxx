#ifndef FMRCXX_INTERNAL_IMPL_STDITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_STDITERATOR_HPP_

#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>
#include <fmrcxx/internal/StdContainerIterator.h>

namespace fmrcxx {

template <typename T, typename It>
StdContainerIterator<T, It>::StdContainerIterator(It&& start, It&& end) :
	Iterator<T>(),
	current(std::move(start)),
	end(std::move(end)) {
}

template <typename T, typename It>
bool StdContainerIterator<T, It>::fullyConsumed() {
	if (Iterator<T>::fullyConsumed()) {
		return true;
	}
	return !(this->current < this->end);
}

template <typename T, typename It>
T& StdContainerIterator<T, It>::next() {
	if (fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	T& it = *this->current;
	this->current ++;
	return it;
}

}

#endif
