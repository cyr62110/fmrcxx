#ifndef FMRCXX_IMPL_INTERNAL_COPYINGITERATOR_HPP_
#define FMRCXX_IMPL_INTERNAL_COPYINGITERATOR_HPP_

#include <fmrcxx/internal/CopyingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename It>
CopyingIterator<T, It>::CopyingIterator(It&& iterator) :
	TransformingIterator<T, It, CopyingIterator<T, It>>(std::move(iterator)),
	computedNext() {
}

template <typename T, typename It>
CopyingIterator<T, It>::CopyingIterator(CopyingIterator<T, It>&& rhs) :
	TransformingIterator<T, It, CopyingIterator<T, It>>(std::move(rhs)),
	computedNext(std::move(rhs.computedNext)) {
}

template <typename T, typename It>
T* CopyingIterator<T, It>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	T* pComputedNext = &this->iterator.next();
	if (this->iterator.ownItem() && this->iterator.areItemAllocatedDynamically()) {
		this->iterator.releaseOwnership();
	} else {
		pComputedNext = new T(*pComputedNext);
	}
	this->computedNext.reset(pComputedNext);
	return &(*this->computedNext);
}

template <typename T, typename It>
bool CopyingIterator<T, It>::ownItem() {
	return true;
}

template <typename T, typename It>
bool CopyingIterator<T, It>::areItemAllocatedDynamically() {
	return true;
}

template <typename T, typename It>
void CopyingIterator<T, It>::releaseOwnership() {
	this->computedNext.release();
}

}}

#endif
