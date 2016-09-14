#ifndef FMRCXX_IMPL_ITERATOROPERATION_HPP_
#define FMRCXX_IMPL_ITERATOROPERATION_HPP_

#include <fmrcxx/IteratorOperation.h>

namespace fmrcxx {

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
ResultIt<T, internal::FilteredIterator<T, BaseIt>> IteratorOperation<T, ResultIt, BaseIt>::filter(std::function<bool(const T&)> filterFunction) {
	internal::FilteredIterator<T, BaseIt> filteredIt(filterFunction, std::move(*static_cast<BaseIt*>(this)));
	return ResultIt<T, internal::FilteredIterator<T, BaseIt>>(std::move(filteredIt));
}

}

#endif
