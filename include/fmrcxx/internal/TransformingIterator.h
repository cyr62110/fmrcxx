#ifndef FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_
#define FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_

namespace fmrcxx {

/**
 * \internal
 * \brief Base class for all iterator that apply any kind of transformation on another iterator.
 * \tparam T Type of element contained in the collection we iterate over
 * \tparam It Type of the iterator on which we will apply the transformation
 * \tparam TIt Actual concrete type of the transforming iterator
 *
 * A TransformingIterator can either:
 * - transforms the element from the preceding iterator into another type.
 * - transforms the iterator by sorting, filtering, etc. elements.
 *
 * To create a transforming iterator, you new iterator must extends this class.
 * In addition to override the two constructors, the new iterator will need to define the following function:
 * \code
 * T* doComputeNext();
 * \endcode
 * This function return the next item in the iterator after having applied the transformation or nullptr
 * if the iterator is fully consumed.
 */
template <typename T, typename It, typename TIt>
class TransformingIterator {
public:
	/**
	 * \brief
	 * \param iterator Iterator on which the transformation will be applied.
	 */
	TransformingIterator(It&& iterator);

	/**
	 * \brief Move constructor
	 */
	TransformingIterator(TransformingIterator&& rhs);

	bool fullyConsumed();

	T& next();
protected:
	It iterator;

private:
	/**
	 * \brief Return the next element in the iterator after having applied the transformation. Or nullptr if there is no more element.
	 */
	T* computeNext();

	bool moved;

	T* computedNext;
	bool isNextComputed;
};

}

#include <fmrcxx/internal/impl/TransformingIterator.hpp>

#endif
