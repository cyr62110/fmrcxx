#ifndef FMRCXX_IMPL_ITERATORMAPTERMINALOPERATION_HPP_
#define FMRCXX_IMPL_ITERATORMAPTERMINALOPERATION_HPP_

#include <fmrcxx/IteratorMapTerminalOperation.h>
#include <fmrcxx/exception/UnsupportedContainerTypeException.h>

namespace fmrcxx {

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename... TPs>
Container<typename IteratorMapTerminalOperation<Tuple<Key, Value>, It>::cKey, typename IteratorMapTerminalOperation<Tuple<Key, Value>, It>::cValue, TPs...> IteratorMapTerminalOperation<Tuple<Key, Value>, It>::toMap() {
	Container<cKey, cValue, TPs...> container;
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		const Tuple<Key, Value>& tuple = it.next();
		appendToMap(container,
				internal::TypeUtils<Key>::toReference(tuple.getKey()),
				std::move(internal::TypeUtils<Value>::toReference(tuple.getValue())));
	}
	return container;
}

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::appendToMap(Container<cKey, cValue, TPs...>& container, cKey& key, cValue&& value) {
	throw exception::UnsupportedContainerTypeException();
}

template <typename Key, typename Value, typename It> template <typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::appendToMap(std::map<cKey, cValue, TPs...>& container, cKey& key, cValue&& value) {
	container.emplace(key, std::move(value));
}

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename pValue, typename... TPs>
Container<typename IteratorMapTerminalOperation<Tuple<Key, Value>, It>::cKey, pValue, TPs...> IteratorMapTerminalOperation<Tuple<Key, Value>, It>::copyToMap() {
	Container<cKey, pValue, TPs...> container;
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		const Tuple<Key, Value>& tuple = it.next();
		cValue* value = new cValue(internal::TypeUtils<Value>::toReference(tuple.getValue()));
		appendToMap(container,
				internal::TypeUtils<Key>::toReference(tuple.getKey()),
				value);
	}
	return container;
}

template <typename Key, typename Value, typename It> template <template <typename...> class Container, typename pValue, typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::appendToMap(Container<cKey, pValue, TPs...>& container, cKey& key, cValue* value) {
	throw exception::UnsupportedContainerTypeException();
}

template <typename Key, typename Value, typename It> template <typename pValue, typename... TPs>
void IteratorMapTerminalOperation<Tuple<Key, Value>, It>::appendToMap(std::map<cKey, pValue, TPs...>& container, cKey& key, cValue* value) {
	container.emplace(key, value);
}

}

#endif
