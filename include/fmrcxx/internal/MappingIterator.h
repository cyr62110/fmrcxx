#ifndef FMRCXX_INTERNAL_MAPPINGITERATOR_H_
#define FMRCXX_INTERNAL_MAPPINGITERATOR_H_

#include <memory>
#include <functional>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will map every item in the preceding iterator into another type.
 * \tparam T Type in which the item in the iterator will be mapped into
 * \tparam I Type of item in iterator on which we will apply the transformation
 * \tparam It Type of the iterator on which we will apply the transformation
 * \tparam UseDynamicAlloc Select between the statically-allocated memory model or the dynamic one.
 *
 * ## Usage
 *
 * FIXME
 *
 * ## Memory Models
 *
 * ### Who will own the memory of the newly created object?
 *
 * The strategy chosen by the MappingIterator is that it will OWN the newly created object.
 * This strategy allow a simple memory management if we do not need to keep this object alive at
 * the end of the chain (because it has been mapped to another type again, etc.).
 *
 * If you want to claim this memory, well it is simple also. You just need to map to unique_ptr<T> instead of T.
 * You will be able to claim the memory from unique_ptrs at the end of the chain.
 *
 * ### Where are stored the mapped items ?
 *
 * You can choose between two memory model, using UseDynamicAlloc template parameter:
 *
 * #### Static model
 *
 * With this model, the object returned by the map function will be moved (by using placement new)
 * inside memory held by the MappingIterator. The MappingIterator will also take care of calling placement delete
 * for the moved object.
 *
 * Conclusion:
 * - All memory is allocated on the head. No dynamic allocation at all.
 * - Can only be used with object that can be moved.
 * - Cannot be used to map to pointer nor array.
 * - Adapted for light object that can easily moved.
 *
 * #### Dynamic model
 *
 * With this model, the memory of the mapped object needs to be allocated inside the map function.
 * As the MappingIterator will take the ownership of the allocated memory, you do not need to care about
 * how this memory will be released.
 *
 * Conclusion:
 * - Memory for object is allocated dynamically in the map function
 * - Can be used will all types of object
 * - Adapter for heavy object or object that cannot be moved.
 *
 */
template <typename T, typename I, typename It, bool UseDynamicAlloc>
class MappingIterator : FMRCXX_PRIVATE TransformingIterator<T, It, MappingIterator<T, I, It, UseDynamicAlloc>> {
public:
	MappingIterator(std::function<T(I&)> mapFunction, It&& iterator);

	MappingIterator(MappingIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	class Impl;
	Impl impl;
};

template <typename T, typename I, typename It>
class MappingIterator<T, I, It, true> : FMRCXX_PRIVATE TransformingIterator<T, It, MappingIterator<T, I, It, true>> {
public:
	MappingIterator(std::function<T*(I&)> mapFunction, It&& iterator);

	MappingIterator(MappingIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	class Impl;
	Impl impl;
};

}}

#include <fmrcxx/internal/impl/MappingIterator.hpp>

#endif
