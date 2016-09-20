#ifndef FMRCXX_INTERNAL_IMPL_STDMAPITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_STDMAPITERATOR_HPP_

#include <fmrcxx/internal/StdMapIterator.h>
#include <fmrcxx/exception/NextOperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename Key, typename Value, typename It>
StdMapIterator<Key, Value, It>::StdMapIterator(It&& begin, It&& end) :
	Iterator<Tuple<const Key&, Value&>>(),
	current(std::move(begin)),
	end(std::move(end)),
	first(true) {
}

template <typename Key, typename Value, typename It>
StdMapIterator<Key, Value, It>::StdMapIterator(StdMapIterator<Key, Value, It>&& rhs) :
	Iterator<Tuple<const Key&, Value&>>(std::move(rhs)),
	current(std::move(rhs.current)),
	end(std::move(rhs.end)),
	first(true) {
}

template <typename Key, typename Value, typename It>
bool StdMapIterator<Key, Value, It>::fullyConsumed() {
	if (Iterator<Tuple<const Key&, Value&>>::fullyConsumed()) {
		return true;
	}
	return this->current == this->end;
}

template <typename Key, typename Value, typename It>
Tuple<const Key&, Value&>& StdMapIterator<Key, Value, It>::next() {
	if (this->fullyConsumed()) {
		throw exception::NextOperationOnFullyConsumedIteratorException();
	}
	if (!this->first) {
		((Tuple<Key&, Value&>*)this->pTuple)->~Tuple();
	}
	const Key& key = this->current->first;
	Value& value = this->current->second;
	new (this->pTuple) Tuple<const Key&, Value&>(key, value);
	this->current ++;
	this->first = false;
	return *(Tuple<const Key&, Value&>*)this->pTuple;
}

}

#endif
