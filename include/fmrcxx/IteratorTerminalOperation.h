#ifndef FMRCXX_ITERATORTERMINALOPERATION_H_
#define FMRCXX_ITERATORTERMINALOPERATION_H_

#include <memory>
#include <functional>
#include <vector>

namespace fmrcxx {

template <typename T, typename It>
class IteratorTerminalOperation {
public:
	/**
	 * \brief Run the function passed in parameter for each element in the iterator.
	 */
	void forEach(std::function<void(T&)> function);

	template <typename Accumultator>
	std::unique_ptr<Accumultator> reduce(std::unique_ptr<Accumultator> accumulator, std::function<void(Accumultator&, T&)> reduceFunction);

	/**
	 * \brief Return the first element present in the iterator.
	 *
	 */
	//FIXME Optional<T> first();
};

}

#include <fmrcxx/impl/IteratorTerminalOperation.hpp>

#endif
