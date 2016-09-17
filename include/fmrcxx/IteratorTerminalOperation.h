#ifndef FMRCXX_ITERATORTERMINALOPERATION_H_
#define FMRCXX_ITERATORTERMINALOPERATION_H_

#include <memory>
#include <functional>
#include <vector>
#include <map>

namespace fmrcxx {

template <typename T, typename It>
class IteratorTerminalOperation {
public:
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
