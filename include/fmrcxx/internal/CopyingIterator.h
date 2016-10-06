#ifndef FMRCXX_INTERNAL_COPYINGITERATOR_H_
#define FMRCXX_INTERNAL_COPYINGITERATOR_H_

#include <memory>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will ensure that every item is a copy of the original item.
 * \tparam T Type of item in the iterator on which we will apply the transformation
 * \tparam It Type of the iterator on which we will apply the transformation
 *
 * Most transforming iterator that transform the number of item in the iterator but not the items
 * themselve will transmit a reference to the original item. This approach is good for performance
 * but has the downside that any modification on the object will affect the original.
 *
 * The copy transformation will ensure that all items return by it are a copy of the orginal item
 * if they come directly from the source iterator. It will only copy if needed, if the item
 * has been allocated dynamically by one of the preceding transforming iterator, the copy
 * iterator will only claim the memory instead of allocating new memory.
 *
 * ## Constraint
 *
 * - The item must provide a copy constructor.
 *
 * ## Memory model
 *
 * All item returned by the copy iterator are dynamically allocated.
 * The iterator will own the allocated items, therefore the memory will be automatically
 * released by the iterator.
 *
 */
template <typename T, typename It>
class CopyingIterator : public TransformingIterator<T, It, CopyingIterator<T, It>> {
public:
	/**
	 * \brief Construct an iterator
	 * \param iterator Iterator from which the items will be copied if needed.
	 */
	CopyingIterator(It&& iterator);

	/**
	 * \brief Move constructor
	 */
	CopyingIterator(CopyingIterator&& rhs);

	bool ownItem();
	bool areItemAllocatedDynamically();
	void releaseOwnership();

	T* doComputeNext();
FMRCXX_PRIVATE:
	std::unique_ptr<T> computedNext;
};

}}

#include <fmrcxx/internal/impl/CopyingIterator.hpp>

#endif
