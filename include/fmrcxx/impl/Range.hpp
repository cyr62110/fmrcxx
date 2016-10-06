#ifndef FMRCXX_IMPL_RANGE_HPP_
#define FMRCXX_IMPL_RANGE_HPP_

#include <fmrcxx/Range.h>
#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T>
Range<T>::Range(T start, T end, T increment) :
	Iterator<T>(),
	previous(start),
	current(start),
	end(end),
	increment(increment) {
}

template <typename T>
Range<T>::Range(Range&& rhs) :
	Iterator<T>(std::move(rhs)),
	previous(rhs.previous),
	current(rhs.current),
	end(rhs.end),
	increment(rhs.increment) {
}

template <typename T>
bool Range<T>::fullyConsumed() {
	if (Iterator<T>::fullyConsumed()) {
		return true;
	}
	if (increment > 0) {
		return this->current > this->end;
	} else {
		return this->current < this->end;
	}
}

template <typename T>
T& Range<T>::next() {
	if (this->fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	this->previous = this->current;
	this->current += this->increment;
	return this->previous;
}

template <typename T>
bool Range<T>::ownItem() {
	return true;
}

}

#endif
