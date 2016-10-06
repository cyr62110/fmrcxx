#ifndef FMRCXX_INTERNAL_EACHINGITERATOR_H_
#define FMRCXX_INTERNAL_EACHINGITERATOR_H_

#include <functional>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will perform an operation on every item.
 * \tparam T Type of item in the iterator on which we will apply the transformation.
 * \tparam It Type of the iterator on which we will apply the transformation.
 *
 * The each operation will perform the function provided in constructor on every
 * item of the preceding iterator. The item may be modified by the function.
 * As this operation does not modify the number of items or there type, it
 * can be inserted anywhere between two operations to add logging for ex.
 *
 * Like all transforming operation, the each operator share their lazy nature.
 * The function will only be executed on a item when it will be returned by next.
 * forEach is the terminal counterpart to the each operation.
 */
template <typename T, typename It>
class EachingIterator : public TransformingIterator<T, It, EachingIterator<T, It>> {
public:
	/**
	 * \brief Constructor
	 * \param eachFunction function executed for each item in the iterator
	 * \param iterator
	 */
	EachingIterator(std::function<void(T&)> eachFunction, It&& iterator);

	/**
	 * \brief Move constructor
	 */
	EachingIterator(EachingIterator&& rhs);

	T* doComputeNext();
FMRCXX_PRIVATE:
	std::function<void(T&)> eachFunction;
};

}}

#include <fmrcxx/internal/impl/EachingIterator.hpp>

#endif
