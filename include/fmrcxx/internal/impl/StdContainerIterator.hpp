#ifndef FMRCXX_INTERNAL_IMPL_STDITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_STDITERATOR_HPP_

#include <fmrcxx/internal/StdContainerIterator.h>
#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T, typename It>
StdContainerIterator<T, It>::StdContainerIterator(It&& begin, It&& end) :
	Iterator<T>(),
	current(std::move(begin)),
	end(std::move(end)) {
}

template <typename T, typename It>
StdContainerIterator<T, It>::StdContainerIterator(StdContainerIterator<T, It>&& rhs) :
	Iterator<T>(std::move(rhs)),
	current(std::move(rhs.current)),
	end(std::move(rhs.end)) {
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
	if (this->fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	T& it = *this->current;
	this->current ++;
	return it;
}

}

#endif
