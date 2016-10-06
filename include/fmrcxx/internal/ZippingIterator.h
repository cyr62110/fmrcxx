#ifndef FMRCXX_INTERNAL_ZIPPINGITERATOR_H_
#define FMRCXX_INTERNAL_ZIPPINGITERATOR_H_

#include <fmrcxx/Tuple.h>
#include <fmrcxx/Macro.h>
#include <fmrcxx/internal/TransformingIterator.h>

namespace fmrcxx {
namespace internal {

/**
 * \brief Transforming iterator that will transform two iterator into a single iterator of Tuple
 * \tparam T1
 * \tparam It1
 * \tparam T2
 * \tparam It2
 *
 * Combine two iterator into a single iterator of tuple. The key part of the tuple will come from the
 * first iterator, the value part will come from the second iterator. As soon as one of the iterator
 * is fully consumed, this iterator will be considered as fully consumed.
 */
template <typename T1, typename It1,  typename T2, typename It2>
class ZippingIterator : FMRCXX_PRIVATE TransformingIterator<Tuple<T1&, T2&>, It1, ZippingIterator<T1, It1, T2, It2>> {
public:
	/**
	 * \brief Construct the zipping iterator.
	 * \param it1 First iterator.
	 * \param it2 Second iterator.
	 */
	ZippingIterator(It1&& it1, It2&& it2);

	/**
	 * \brief Move constructor
	 */
	ZippingIterator(ZippingIterator&& rhs);

	~ZippingIterator();

FMRCXX_PRIVATE:
	Tuple<T1&, T2&>* doComputeNext();

	bool hasComputedNext;
	std::uint8_t pComputedNext[sizeof(Tuple<T1&, T2&>)];
	It2&& iterator2;
};

}}

#include <fmrcxx/internal/impl/ZippingIterator.hpp>

#endif
