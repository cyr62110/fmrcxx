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
 * \tparam T
 * \tparam I
 * \tparam It Type of the iterator on which we will apply the transformation
 * \tparam UseDynamicAlloc Select between the statically-allocated memory model or the dynamic one.
 *
 * ## Memory Models
 *
 * As we transform an object into another, we need to answer this question:
 * Who will own the memory of the newly created object?
 *
 * The strategy chosen by the MappingIterator is that it will OWN the newly created object.
 * This strategy allow a simple memory management if we do not need to keep this object alive at
 * the end of the chain (because it has been mapped to another type again, etc.).
 *
 * If you want to claim this memory, well it is simple also. You just need to map to unique_ptr<T> instead of T.
 * You will be able to claim the memory from unique_ptrs at the end of the chain.
 *
 *
 *
 * ### Statically-allocated memory
 *
 * ### Dynamically-allocated memory
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

#include <fmrcxx/internal/MappingIterator.hpp>

#endif
