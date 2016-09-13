#ifndef FMRCXX_IMPL_STDITERATOR_HPP_
#define FMRCXX_IMPL_STDITERATOR_HPP_

#include <fmrcxx/StdIterator.h>

#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T, typename It>
StdIterator<T, It>::StdIterator(It&& start, It&& end) :
	Iterator<T>(),
	current(std::move(start)),
	end(std::move(end)) {
}

template <typename T, typename It>
bool StdIterator<T, It>::fullyConsumed() {
	if (Iterator<T>::fullyConsumed()) {
		return true;
	}
	return !(this->current < this->end);
}

template <typename T, typename It>
T& StdIterator<T, It>::next() {
	if (fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	T& it = *this->current;
	this->current ++;
	return it;
}

}

#endif
