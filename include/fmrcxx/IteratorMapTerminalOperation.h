#ifndef FMRCXX_ITERATORMAPTERMINALOPERATION_H_
#define FMRCXX_ITERATORMAPTERMINALOPERATION_H_

#include <map>

#include <fmrcxx/Tuple.h>

namespace fmrcxx {

template <typename T, typename It>
class IteratorMapTerminalOperation {
};

template <typename Key, typename Value, typename It>
class IteratorMapTerminalOperation<Tuple<Key, Value>, It> {
public:
	/**
	 * \brief Move all items in the iterator into a new map container.
	 * \tparam Container Type of the container in which the item will be stored.
	 * \tparam TPs Other template params of the container.
	 *
	 * ## Constraints
	 *
	 * - Container must provide a default constructor.
	 * - Key & Value must provide a move constructor.
	 *
	 * ## Memory model
	 *
	 * Both key and value of all items will be move-constructed inside the container. The ownership of
	 * the original objects will therefore not be modified.
	 */
	template <template <typename...> class Container, typename... TPs>
	Container<Key, Value, TPs...> toMap();

private:
	template <template <typename...> class Container, typename... TPs>
	void internalToMap(Container<Key, Value, TPs...>& container);
	template <typename... TPs>
	void internalToMap(std::map<Key, Value, TPs...>& map);
};

}

#include <fmrcxx/impl/IteratorMapTerminalOperation.hpp>

#endif
