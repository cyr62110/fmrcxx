#ifndef FMRCXX_IMPL_ITERATORMAPTERMINALOPERATION_HPP_
#define FMRCXX_IMPL_ITERATORMAPTERMINALOPERATION_HPP_

#include <fmrcxx/IteratorMapTerminalOperation.h>
#include <fmrcxx/exception/UnsupportedContainerTypeException.h>

namespace fmrcxx {

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename... TPs>
Container<Key, Value, TPs...> IteratorMapTerminalOperation<Tuple<Key, Value>, It>::toMap() {
	Container<Key, Value, TPs...> container;
	internalToMap(container);
	return container;
}

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::internalToMap(Container<Key, Value, TPs...>& container) {
	throw exception::UnsupportedContainerTypeException();
}

template <typename Key, typename Value, typename It> template <typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::internalToMap(std::map<Key, Value, TPs...>& map) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		const Tuple<Key, Value>& tuple = it.next();
		map.emplace(tuple.getKey(), std::move(tuple.getValue()));
	}
}

}

#endif
