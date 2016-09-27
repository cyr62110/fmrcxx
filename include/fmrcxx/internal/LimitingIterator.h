#ifndef FMRCXX_INTERNAL_LIMITINGITERATOR_H_
#define FMRCXX_INTERNAL_LIMITINGITERATOR_H_

#include <cstdint>

#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
class LimitingIterator : public TransformingIterator<T, It, LimitingIterator<T, It>> {
public:
	/**
	 * \brief Construct the transforming iterator
	 * \param limit Number of items that the iterator will contains at most.
	 * \param iterator Iterator that will be limited.
	 */
	LimitingIterator(std::uint32_t limit, It&& iterator);

	/**
	 * \brief Move constructor
	 */
	LimitingIterator(LimitingIterator&& rhs);

FMRCXX_PRIVATE:
	T* doComputeNext();

	std::uint32_t current;
	std::uint32_t limit;
};

}}

#include <fmrcxx/internal/impl/LimitingIterator.hpp>

#endif
