#ifndef FMRCXX_ITERATORTERMINALOPERATION_H_
#define FMRCXX_ITERATORTERMINALOPERATION_H_

#include <memory>
#include <functional>
#include <vector>

namespace fmrcxx {

template <typename T, typename TIt>
class IteratorEndOperation {
public:
	/**
	 * \brief Run the function passed in parameter for each element in the iterator.
	 */
	void forEach(std::function<void(T&)> function);

	template <typename Result>
	std::unique_ptr<Result> reduce(std::unique_ptr<Result> accumulator, std::function<void(Result&, T&) reduceFunction);

	/**
	 * \brief Return the first element present in the iterator.
	 *
	 */
	//FIXME Optional<T> first();
};

}

#include <fmrcxx/impl/IteratorTerminalOperation.hpp>

#endif
