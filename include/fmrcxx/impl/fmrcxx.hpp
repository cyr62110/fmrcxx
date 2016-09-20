#ifndef FMRCXX_IMPL_FMRCXX_HPP_
#define FMRCXX_IMPL_FMRCXX_HPP_

#include <fmrcxx/fmrcxx.h>

namespace fmrcxx {

template <typename T, template <typename...> class Container, typename... TTs>
StdContainerIterator<T, typename Container<T, TTs...>::iterator> iterateOver(Container<T, TTs...>& container) {
	return StdContainerIterator<T, typename Container<T, TTs...>::iterator>(container.begin(), container.end());
}

template <typename T, template <typename...> class Container, typename... TTs>
StdContainerIterator<T, typename Container<T, TTs...>::iterator> reverseIterateOver(Container<T, TTs...>& container) {
	return StdContainerIterator<T, typename Container<T, TTs...>::iterator>(container.rbegin(), container.rend());
}

template <typename Key, typename Value, template <typename...> class MapContainer, typename... TTs>
StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator> iterateOverMap(MapContainer<Key, Value, TTs...>& container) {
	return StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator>(container.begin(), container.end());
}

template <typename Key, typename Value, template <typename...> class MapContainer, typename... TTs>
StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator> reverseIterateOverMap(MapContainer<Key, Value, TTs...>& container) {
	return StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator>(container.rbegin(), container.rend());
}

}

#endif
