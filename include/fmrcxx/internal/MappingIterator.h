#ifndef FMRCXX_INTERNAL_MAPPINGITERATOR_H_
#define FMRCXX_INTERNAL_MAPPINGITERATOR_H_

#include <memory>
#include <functional>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \internal
 */
template <typename T, typename I, typename It>
class MappingIterator : FMRCXX_PRIVATE TransformingIterator<T, It, MappingIterator<T, I, It>> {
public:
	MappingIterator(std::function<T(I&)> mapFunction, It&& iterator);

	MappingIterator(MappingIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	std::function<T(I&)> mapFunction;
	std::unique_ptr<T> computedNextPtr;
};

}}

#include <fmrcxx/internal/MappingIterator.hpp>

#endif
