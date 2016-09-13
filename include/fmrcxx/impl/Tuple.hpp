#ifndef FMRCXX_IMPL_TUPLE_HPP_
#define FMRCXX_IMPL_TUPLE_HPP_

#include <fmrcxx/Tuple.h>

namespace fmrcxx {

template <typename Key, typename Value>
Tuple<Key, Value>::Tuple(Key key, Value value) :
	key(key),
	value (value) {
}

template <typename Key, typename Value>
Key Tuple<Key, Value>::getKey() {
	return this->key;
}

template <typename Key, typename Value>
Value Tuple<Key, Value>::getValue() {
	return this->value;
}

}

#endif
