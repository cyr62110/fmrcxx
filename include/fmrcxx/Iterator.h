#ifndef COLLECTION_ITERATOR_H_
#define COLLECTION_ITERATOR_H_

#include <cstddef>

#include <fmrcxx/IteratorTransformingOperation.h>
#include <fmrcxx/IteratorTerminalOperation.h>

namespace fmrcxx {

/**
 * \brief Class providing convenient method to iterate over a collection.
 *
 *
 * Before using an iterator, make sure the following rules are respected:
 * - T must not be a pointer type. Reference type are allowed.
 */
template <typename T, typename It = std::nullptr_t>
class Iterator :
		public IteratorTransformingOperation<T, Iterator, Iterator<T, It>>,
		public IteratorTerminalOperation<T, Iterator<T, It>> {
public:
	/**
	 * \internal
	 * \brief Construct an iterator using one of its implementation
	 */
	Iterator(It&& iterator);

	/**
	 * \internal
	 * \brief Construct an iterator and its implementation. Implementation will be constructed with provided arguments.
	 *
	 */
	template <typename... Args>
	Iterator(Args&&... args);

	/**
	 * \brief Iterator cannot be copied
	 */
	Iterator(Iterator& iterator) = delete;

	/**
	 * \brief Move constructor
	 */
	Iterator(Iterator&& iterator);

	/**
	 * \brief Return true if the iterator has a next element.
	 */
	bool fullyConsumed();

	/**
	 * \brief Return a reference to the next object on the collection we iterate over.
	 */
	T& next();

	/**
	 * \brief Return true if the memory of the next object has been allocated by the iterator.
	 */
	bool ownItem();

	/**
	 * \brief Return true if the memory of the 'next object has been allocated dynamically.
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
	 */
	void releaseOwnership();

private:
	bool moved;
	It iterator;
};

}

#include <fmrcxx/impl/Iterator.hpp>

#endif
