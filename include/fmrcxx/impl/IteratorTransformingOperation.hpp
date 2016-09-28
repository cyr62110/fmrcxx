#ifndef FMRCXX_IMPL_ITERATORTRANSFORMINGOPERATION_HPP_
#define FMRCXX_IMPL_ITERATORTRANSFORMINGOPERATION_HPP_

#include <fmrcxx/IteratorTransformingOperation.h>

namespace fmrcxx {

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
ResultIt<T, internal::FilteredIterator<T, BaseIt>> IteratorTransformingOperation<T, ResultIt, BaseIt>::filter(std::function<bool(const T&)> filterFunction) {
	return ResultIt<T, internal::FilteredIterator<T, BaseIt>>(std::move(filterFunction), std::move(*static_cast<BaseIt*>(this)));
}

template <typename T, template<typename, typename> class ResultIt, typename BaseIt> template <typename O>
ResultIt<O, internal::MappingIterator<O, T, BaseIt, false>> IteratorTransformingOperation<T, ResultIt, BaseIt>::map(std::function<O(T&)> mapFunction) {
	return ResultIt<O, internal::MappingIterator<O, T, BaseIt, false>>(std::move(mapFunction), std::move(*static_cast<BaseIt*>(this)));
}

template <typename T, template<typename, typename> class ResultIt, typename BaseIt> template <typename O>
ResultIt<O, internal::MappingIterator<O, T, BaseIt, true>> IteratorTransformingOperation<T, ResultIt, BaseIt>::map(std::function<O*(T&)> mapFunction) {
	return ResultIt<O, internal::MappingIterator<O, T, BaseIt, true>>(std::move(mapFunction), std::move(*static_cast<BaseIt*>(this)));
}

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
ResultIt<T, internal::LimitingIterator<T, BaseIt>> IteratorTransformingOperation<T, ResultIt, BaseIt>::limit(std::uint32_t limit) {
	return ResultIt<T, internal::LimitingIterator<T, BaseIt>>(limit, std::move(*static_cast<BaseIt*>(this)));
}

}

#endif
