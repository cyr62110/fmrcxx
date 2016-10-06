#ifndef FMRCXX_INTERNAL_IMPL_ZIPPINGITERATOR_HPP_
#define FMRCXX_INTERNAL_IMPL_ZIPPINGITERATOR_HPP_

#include <cstring>

#include <fmrcxx/internal/ZippingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T1, typename It1,  typename T2, typename It2>
ZippingIterator<T1, It1, T2, It2>::ZippingIterator(It1&& it1, It2&& it2) :
	TransformingIterator<Tuple<T1&, T2&>, It1, ZippingIterator<T1, It1, T2, It2>>(std::move(it1)),
	iterator2(std::move(it2)),
	hasComputedNext(false) {
}

template <typename T1, typename It1,  typename T2, typename It2>
ZippingIterator<T1, It1, T2, It2>::ZippingIterator(ZippingIterator<T1, It1, T2, It2>&& rhs) :
	TransformingIterator<Tuple<T1&, T2&>, It1, ZippingIterator<T1, It1, T2, It2>>(std::move(rhs)),
	iterator2(std::move(rhs.iterator2)),
	hasComputedNext(rhs.hasComputedNext) {
	std::memcpy(this->pComputedNext, rhs.pComputedNext, sizeof(Tuple<T1&, T2&>));
}

template <typename T1, typename It1,  typename T2, typename It2>
ZippingIterator<T1, It1, T2, It2>::~ZippingIterator() {
	if (this->hasComputedNext) {
		((Tuple<T1&, T2&>*)this->pComputedNext)->~Tuple();
		this->hasComputedNext = false;
	}
}

template <typename T1, typename It1,  typename T2, typename It2>
Tuple<T1&, T2&>* ZippingIterator<T1, It1, T2, It2>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	if (this->iterator2.fullyConsumed()) {
		return nullptr;
	}

	T1& t1 = this->iterator.next();
	T2& t2 = this->iterator2.next();
	new (this->pComputedNext) Tuple<T1&, T2&>(t1, t2);
	return (Tuple<T1&, T2&>*)this->pComputedNext;
}

}}

#endif
