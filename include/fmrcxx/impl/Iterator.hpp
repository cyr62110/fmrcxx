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

template <typename T, typename It> template <typename... Args>
Iterator<T, It>::Iterator(Args&&... args) :
	moved(false),
	iterator(std::forward<Args>(args)...) {
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

template <typename T, typename It>
bool Iterator<T, It>::ownItem() {
	if (this->moved) {
		return false;
	}
	return this->iterator.ownItem();
}

template <typename T, typename It>
bool Iterator<T, It>::areItemAllocatedDynamically() {
	if (this->moved) {
		return false;
	}
	return this->iterator.areItemAllocatedDynamically();
}

template <typename T, typename It>
void Iterator<T, It>::releaseOwnership() {
	if (this->moved) {
		return;
	}
	return this->iterator.releaseOwnership();
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

	bool ownItem() {
		return false;
	}

	bool areItemAllocatedDynamically() {
		return false;
	}

	void releaseOwnership() {
		// Nothing to do here since the iterator does not own the items.
	}
private:
	bool moved;
};

}

#endif
