#ifndef FMRCXX_INTERNAL_STDCOLLECTIONITERATOR_H_
#define FMRCXX_INTERNAL_STDCOLLECTIONITERATOR_H_

#include <fmrcxx/Iterator.h>
#include <fmrcxx/IteratorTransformingOperation.h>
#include <fmrcxx/IteratorTerminalOperation.h>

namespace fmrcxx {

/**
 * \brief Implementation of iterator that will iterate over and standard container (vector, etc.) using its std::iterator.
 * \tparam T Type of item in the collection
 * \tparam T Concrete type of std::iterator taht will be used to iterate over the collection
 */
template <typename T, typename It>
class StdContainerIterator :
		public Iterator<T>,
		public IteratorTransformingOperation<T, Iterator, StdContainerIterator<T, It>>,
		public IteratorTerminalOperation<T, StdContainerIterator<T, It>> {
public:
	/**
	 * \brief Constructor that will take a begin and a end iterator
	 * \param begin Iterator to the beginning of the container
	 * \param end Iterator to the end of the container
	 */
	StdContainerIterator(It&& begin, It&& end);

	StdContainerIterator(StdContainerIterator& rhs) = delete;

	/**
	 * \brief Move constructor
	 */
	StdContainerIterator(StdContainerIterator&& rhs);

	bool fullyConsumed();

	T& next();
private:
	It current;
	It end;
};

}

#include <fmrcxx/internal/impl/StdContainerIterator.hpp>

#endif
