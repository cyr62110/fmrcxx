#ifndef FMRCXX_ITERATORTERMINALOPERATION_H_
#define FMRCXX_ITERATORTERMINALOPERATION_H_

#include <memory>
#include <functional>
#include <vector>
#include <map>

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
 * Due to the lazy nature of Iterator and transforming operation on it, all actual operation are actually
 * executed when a terminal operation is called.
 */
template <typename T, typename It>
class IteratorTerminalOperation {
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
};

}

#include <fmrcxx/impl/IteratorTerminalOperation.hpp>

#endif
