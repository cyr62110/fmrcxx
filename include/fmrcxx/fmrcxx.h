#ifndef FMRCXX_FMRCXX_H_
#define FMRCXX_FMRCXX_H_

#include <fmrcxx/Iterator.h>
#include <fmrcxx/internal/StdMapIterator.h>
#include <fmrcxx/internal/StdContainerIterator.h>

namespace fmrcxx {

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> iterateOver(Container<T>& container);

template <typename T, template <typename, typename... Others> class Container>
StdContainerIterator<T, typename Container<T>::iterator> reverseIterateOver(Container<T>& container);

template <typename Key, typename Value, template <typename, typename, typename...> class MapContainer>
StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator> iterateOver(MapContainer<Key, Value>& container);

template <typename Key, typename Value, template <typename, typename, typename...> class MapContainer>
StdMapIterator<Key, Value, typename MapContainer<Key, Value>::iterator> reverseIterateOver(MapContainer<Key, Value>& container);

}

#include <fmrcxx/impl/fmrcxx.hpp>

#endif
