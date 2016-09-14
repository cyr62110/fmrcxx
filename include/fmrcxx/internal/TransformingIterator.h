#ifndef FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_
#define FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_

namespace fmrcxx {

/**
 * \internal
 * \brief Base class for all iterator that transforms an other iterator.
 */
template <typename T, typename It>
class TransformingIterator {
public:
	TransformingIterator(It&& iterator);

	TransformingIterator(TransformingIterator&& rhs);

	bool fullyConsumed();

	T& next();

	const T* computeNext();
private:
	bool moved;

	It iterator;

	T* computedNext;
	bool isNextComputed;
};

}

#include <fmrcxx/internal/TransformingIterator.hpp>

#endif
