#ifndef FMRCXX_FMRCXX_H_
#define FMRCXX_FMRCXX_H_

#include <fmrcxx/Iterator.h>
#include <fmrcxx/internal/StdMapIterator.h>
#include <fmrcxx/internal/StdContainerIterator.h>

namespace fmrcxx {

template <typename T, template <typename...> class Container, typename... TTs>
StdContainerIterator<T, typename Container<T, TTs...>::iterator> iterateOver(Container<T, TTs...>& container);

template <typename T, template <typename... Others> class Container, typename... TTs>
StdContainerIterator<T, typename Container<T>::iterator> reverseIterateOver(Container<T>& container);

template <typename Key, typename Value, template <typename...> class MapContainer, typename... TTs>
StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator> iterateOverMap(MapContainer<Key, Value, TTs...>& container);

template <typename Key, typename Value, template <typename...> class MapContainer, typename... TTs>
StdMapIterator<Key, Value, typename MapContainer<Key, Value, TTs...>::iterator> reverseIterateOverMap(MapContainer<Key, Value, TTs...>& container);

}

#include <fmrcxx/impl/fmrcxx.hpp>

#endif
