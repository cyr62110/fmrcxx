#ifndef FMRCXX_ITERATORTERMINALOPERATION_H_
#define FMRCXX_ITERATORTERMINALOPERATION_H_

#include <memory>
#include <functional>
#include <vector>
#include <map>

#include <fmrcxx/IteratorMapTerminalOperation.h>
#include <fmrcxx/IteratorArithmeticTerminalOperation.h>

namespace fmrcxx {

/**
 * \brief Provides common terminal operations for iterator.
 * \tparam T Type of item in the iterator
 * \tparam It Type of the iterator on which the operation are executed
 *
 * ## Terminal operation
 *
 * A terminal operation is an operation that will consume the iterator to output its results.
 * Therefore, you cannot chain any more operation after a terminal operation.
 *
 * ## Lazy
 *
 * Due to the lazy nature of Iterator and transforming operation on it, all tranformation are applied
 * on the iterator
 */
template <typename T, typename It>
class IteratorTerminalOperation :
	public IteratorMapTerminalOperation<T, It>,
	public IteratorArithmeticTerminalOperation<T, It> {
public:
	/**
	 * \brief Return the number of item in the iterator
	 */
	unsigned long count();

	/**
	 * \brief Run the function passed in parameter for each element in the iterator.
	 */
	void forEach(std::function<void(T&)> function);

	/**
	 * \brief Reduce the list of item to a single value.
	 * \tparam Acc Type of the accumulator
	 * \param startValue Value passed as accumulator to the first call of the reduce function.
	 * \param reduceFunction Function that will be used to reduce the list.
	 */
	template <typename Acc>
	Acc reduce(Acc startValue, std::function<Acc(Acc&, const T&)> reduceFunction);

	/**
	 * \brief Reduce the list of item to a single value.
	 * \tparam Acc Type of the accumulator
	 * \param accumulator Reference to the accumulator.
	 * \param reduceFunction Function that will be used to reduce the list.
	 */
	template <typename Acc>
	void reduce(Acc& accumulator, std::function<void(Acc&, const T&)> reduceFunction);

	/**
	 * \brief Return the first element present in the iterator.
	 *
	 */
	//FIXME Optional<T> first();

	/**
	 * \brief Return true if all items in the iterator match the condition.
	 */
	bool allMatch(std::function<bool(const T&)> condition);

	/**
	 * \brief Return true if any item in the iterator match the condition.
	 */
	bool anyMatch(std::function<bool(const T&)> condition);

	/**
	 * \brief Return true if no item in the iterator match the condition.
	 */
	bool noneMatch(std::function<bool(const T&)> condition);

	/**
	 * \brief Move all items in the iterator into a new container.
	 * \tparam Container Type of the container in which the item will be stored.
	 * \tparam TPs Other template params of the container.
	 *
	 * ## Constraints
	 *
	 * - Container must provide a default constructor.
	 * - T must provide a move constructor.
	 *
	 * ## Memory model
	 *
	 * All items will be move-constructed inside the container. The ownership of
	 * the original objects will therefore not be modified.
	 */
	template <template <typename...> class Container, typename... TPs>
	Container<T, TPs...> to();

	/**
	 * \brief Copy all items in the iterator into a new container.
	 * \tparam Container Type of the container in which the item will be stored.
	 * \tparam TPs Other template params of the container.
	 *
	 * ## Constraints
	 *
	 * - Container must provide a default constructor.
	 * - T must provide a copy constructor.
	 *
	 * ## Memory model
	 *
	 * This operation will claim ownership of all memory dynamically allocated inside iterators.
	 * If the item memory has not been dynamically allocated or if the memory is not owned by
	 * the iterator, the item will be copied into newly dynamically allocated memory.
	 *
	 */
	template <template <typename...> class Container, typename... TPs>
	Container<T*, TPs...> copyTo();

private:
	template <template <typename...> class Container, typename... TPs>
	void internalTo(Container<T, TPs...>& container);
	template <typename... TPs>
	void internalTo(std::vector<T, TPs...>& vector);
	// FIXME Implements for all std containers: list, set, etc...
};

}

#include <fmrcxx/impl/IteratorTerminalOperation.hpp>

#endif
