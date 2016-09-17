#ifndef FMRCXX_INTERNAL_MAPPINGITERATOR_HPP_
#define FMRCXX_INTERNAL_MAPPINGITERATOR_HPP_

#include <fmrcxx/internal/MappingIterator.h>

namespace fmrcxx {
namespace internal {

template <typename T, typename I, typename It, bool UseDynamicAlloc>
class MappingIterator<T, I, It, UseDynamicAlloc>::Impl {
public:
	Impl(std::function<T(I&)>&& mapFunction) :
		mapFunction(std::move(mapFunction)),
		hasComputedNext(false) {
	}

	Impl(Impl&& rhs) :
		mapFunction(std::move(rhs.mapFunction)),
		hasComputedNext(false) {
	}

	~Impl() {
		free();
	}

	void free() {
		if (hasComputedNext) {
			((T*)computeNextBytes)->~T();
			hasComputedNext = false;
		}
	}

	void swap(T&& item) {
		if (hasComputedNext) {
			free();
		}
		new (computeNextBytes) T(std::forward<T>(item));
		hasComputedNext = true;
	}

	std::function<T(I&)> mapFunction;
	bool hasComputedNext;
	std::uint8_t computeNextBytes[sizeof(T)];
};

template <typename T, typename I, typename It, bool UseDynamicAlloc>
MappingIterator<T, I, It, UseDynamicAlloc>::MappingIterator(std::function<T(I&)> mapFunction, It&& iterator) :
	TransformingIterator<T, It, MappingIterator<T, I, It, UseDynamicAlloc>>(std::move(iterator)),
	impl(std::move(mapFunction)) {
}

template <typename T, typename I, typename It, bool UseDynamicAlloc>
MappingIterator<T, I, It, UseDynamicAlloc>::MappingIterator(MappingIterator&& rhs) :
	TransformingIterator<T, It, MappingIterator<T, I, It, UseDynamicAlloc>>(std::move(rhs)),
	impl(std::move(rhs.impl)) {
}

template <typename T, typename I, typename It, bool UseDynamicAlloc>
T* MappingIterator<T, I, It, UseDynamicAlloc>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	T computedNext = this->impl.mapFunction(this->iterator.next());
	this->impl.swap(std::move(computedNext));
	return (T*)this->impl.computeNextBytes;
}

template <typename T, typename I, typename It>
class MappingIterator<T, I, It, true>::Impl {
public:
	Impl(std::function<T*(I&)>&& mapFunction) :
		mapFunction(std::move(mapFunction)),
		pComputedNext() {
	}

	Impl(Impl&& rhs) :
		mapFunction(std::move(rhs.mapFunction)),
		pComputedNext(std::move(rhs.pComputedNext)) {
	}

	std::function<T*(I&)> mapFunction;
	std::unique_ptr<T> pComputedNext;
};

template <typename T, typename I, typename It>
MappingIterator<T, I, It, true>::MappingIterator(std::function<T*(I&)> mapFunction, It&& iterator) :
	TransformingIterator<T, It, MappingIterator<T, I, It, true>>(std::move(iterator)),
	impl(std::move(mapFunction)) {
}

template <typename T, typename I, typename It>
T* MappingIterator<T, I, It, true>::doComputeNext() {
	if (this->iterator.fullyConsumed()) {
		return nullptr;
	}
	T* pComputedNext = this->impl.mapFunction(this->iterator.next());
	this->impl.pComputedNext.reset(pComputedNext);
	return &(*this->impl.pComputedNext);
}

}}

#endif
