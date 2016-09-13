#ifndef FMRCXX_IMPL_ITERATOR_HPP_
#define FMRCXX_IMPL_ITERATOR_HPP_

#include <fmrcxx/Iterator.h>

#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T, typename It>
Iterator<T, It>::Iterator(It&& iterator) :
	moved(false),
	iterator(std::move(iterator)) {

}

template <typename T, typename It>
Iterator<T, It>::Iterator(Iterator<T, It>&& iterator) :
	moved(false),
	iterator(std::move(iterator.iterator)) {
	iterator.moved = true;
}

template <typename T, typename It>
T& Iterator<T, It>::next() {
	return this->iterator.next();
}

template <typename T, typename It>
bool Iterator<T, It>::fullyConsumed() {
	if (this->moved) {
		return true;
	}
	return this->iterator.fullyConsumed();
}

template <typename T>
class Iterator<T, std::nullptr_t> {
public:
	Iterator() :
		moved(false) {
	}

	Iterator(Iterator&& rhs) :
		moved(false) {
		rhs.moved = true;
	}

	T& next() {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}

	bool fullyConsumed() {
		return this->moved;
	}
private:
	bool moved;
};

}

#endif
