#ifndef FMRCXX_IMPL_MAPITERATOR_HPP_
#define FMRCXX_IMPL_MAPITERATOR_HPP_

#include <fmrcxx/MapIterator.h>

namespace fmrcxx {

template <typename Key, typename Key>
MapIterator<Key, Value>::MapIterator() :
	moved(false) {
}

template <typename Key, typename Key>
MapIterator<Key, Value>::MapIterator(MapIterator&& rhs) :
	moved(false) {
	rhs.moved = true;
}

template <typename Key, typename Key>
bool MapIterator<Key, Value>::fullyConsumed() {
	return this->moved;
}

}

#endif
