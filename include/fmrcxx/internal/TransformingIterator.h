#ifndef FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_
#define FMRCXX_INTERNAL_TRANSFORMINGITERATOR_H_

namespace fmrcxx {

/**
 * \brief Base class for all iterator that apply any kind of transformation on another iterator.
 * \tparam T Type of element contained in the collection we iterate over
 * \tparam It Type of the iterator on which we will apply the transformation
 * \tparam TIt Actual concrete type of the transforming iterator
 *
 * A TransformingIterator can either:
 * - transforms the element from the preceding iterator into another type.
 * - transforms the iterator by sorting, filtering, etc. elements.
 *
 * ## Lazy
 *
 * By design, all transforming operations are lazy. Nothing is computed until next() or fullyConsumed() are
 * called.
 *
 * ## Writing your own TransformingIterator
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
	 * \param iterator Iterator on which the transformation will be applied. It will be refered as preceding iterator in the whole documentation.
	 */
	TransformingIterator(It&& iterator);

	/**
	 * \brief Move constructor
	 */
	TransformingIterator(TransformingIterator&& rhs);

	bool fullyConsumed();

	T& next();

	/**
	 * \brief Return true if the memory of the next object has been allocated by the iterator.
	 *
	 * By default, it will forward the call to the preceding iterator. This function must
	 * be overridden if this transforming iterator changes the ownership (basically if it
	 * allocates item instead of forwarding them from the preceding iterator).
	 */
	bool ownItem();

	/**
	 * \brief Return true if the memory of the 'next object has been allocated dynamically.
	 *
	 * By default, it will forward the call to the preceding iterator. This function must
	 * be overridden if this transforming iterator changes the ownership (basically if it
	 * allocates item instead of forwarding them from the preceding iterator).
	 */
	bool areItemAllocatedDynamically();

	/**
	 * \brief Release the ownership of the last object retrieved through next.
	 *
	 * Once the ownership has been released, it is up to you to delete the memory
	 * allocated for the item.
	 *
	 * If the iterator does not own the item or the item are not dynamically allocation,
	 * this method will have no effect.
	 *
	 * By default, it will forward the call to the preceding iterator. This function must
	 * be overridden if this transforming iterator changes the ownership (basically if it
	 * allocates item instead of forwarding them from the preceding iterator).
	 */
	void releaseOwnership();

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
