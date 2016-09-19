#ifndef FMRCXX_IMPL_FMRCXX_HPP_
#define FMRCXX_IMPL_FMRCXX_HPP_

namespace fmrcxx {

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> iterateOver(Container<T>& container) {
	return StdContainerIterator<T, typename Container<T>::iterator>(container.begin(), container.end());
}

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> reverseIterateOver(Container<T>& container) {
	return StdContainerIterator<T, typename Container<T>::iterator>(container.rbegin(), container.rend());
}

template <typename Key, typename Value, template <typename, typename, typename...> class MapContainer>
StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator> iterateOver(MapContainer<Key, Value>& container) {
	return StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator>(container.begin(), container.end());
}

template <typename Key, typename Value, template <typename, typename, typename...> class MapContainer>
StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator> reverseIterateOver(MapContainer<Key, Value>& container) {
	return StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator>(container.rbegin(), container.rend());
}

}

#endif
