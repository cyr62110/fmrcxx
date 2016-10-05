#ifndef FMRCXX_ITERATORMAPTERMINALOPERATION_H_
#define FMRCXX_ITERATORMAPTERMINALOPERATION_H_

#include <map>

#include <fmrcxx/Macro.h>
#include <fmrcxx/Tuple.h>
#include <fmrcxx/internal/TypeUtils.h>

namespace fmrcxx {

template <typename T, typename It>
class IteratorMapTerminalOperation {
};

/**
 * \brief
 */
template <typename Key, typename Value, typename It>
class IteratorMapTerminalOperation<Tuple<Key, Value>, It> {
public:
	using cKey = typename internal::remove_ref_or_ptr<Key>::type;
	using cValue = typename internal::remove_ref_or_ptr<Value>::type;

	/**
	 * \brief Move all items in the iterator into a new map container.
	 * \tparam Container Type of the container in which the item will be stored.
	 * \tparam TPs Other template params of the container.
	 *
	 * ## Constraints
	 *
	 * - Container must provide a default constructor.
	 * - Value must provide a move constructor.
	 * - Key must provide a copy constructor.
	 *
	 * ## Memory model
	 *
	 * Key of all items will be copied inside the container.
	 * If Key is a reference or a pointer, the object referenced will be copied (not the reference or the pointer).
	 *
	 * Value of all items will be move-constructed inside the container.
	 * If Value is a reference or a pointer, the object referenced will be moved (not the reference or the pointer).
	 *
	 * The ownership of the original objects will therefore not be modified.
	 */
	template <template <typename...> class Container, typename... TPs>
	Container<cKey, cValue, TPs...> toMap();

	/**
	 * \brief Copy all items in the iterator into a new map container
	 * \tparam Container Type of the container in which the item will be stored.
	 * \tparam pValue
	 * \tparam TPs Other template params of the container.
	 *
	 * ## Constraints
	 *
	 * - Container must provide a default constructor.
	 * - Key & Value must provide a move constructor.
	 *
	 * ## Memory model
	 *
	 * Key of all items will be copied inside the container.
	 * If Key is a reference or a pointer, the object referenced will be copied (not the reference or the pointer).
	 *
	 * Value of all items will be copy-constructed inside newly dynamically allocated memory before being passed to the container.
	 * If Value is a reference or a pointer, the object referenced will be copied (not the reference or the pointer).
	 *
	 * The ownership of the original objects will therefore not be modified.
	 */
	template <template <typename...> class Container, typename pValue = cValue*, typename... TPs>
	Container<cKey, pValue, TPs...> copyToMap();

FMRCXX_PRIVATE:
	template <template <typename...> class Container, typename... TPs>
	void appendToMap(Container<cKey, cValue, TPs...>& container, cKey& key, cValue&& value);
	template <typename... TPs>
	void appendToMap(std::map<cKey, cValue, TPs...>& container, cKey& key, cValue&& value);
	// FIXME: Create for other types of map

	template <template <typename...> class Container, typename pValue, typename... TPs>
	void appendToMap(Container<cKey, pValue, TPs...>& container, cKey& key, cValue* value);
	template <typename pValue, typename... TPs>
	void appendToMap(std::map<cKey, pValue, TPs...>& container, cKey& key, cValue* value);
	// FIXME: Create for other types of map
};

}

#include <fmrcxx/impl/IteratorMapTerminalOperation.hpp>

#endif
