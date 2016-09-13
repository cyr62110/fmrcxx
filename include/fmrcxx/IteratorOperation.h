#ifndef FMRCXX_ITERATOROPERATION_H_
#define FMRCXX_ITERATOROPERATION_H_

#include <cstddef>
#include <functional>

#include <fmrcxx/internal/FilteredIteratorImpl.h>

namespace fmrcxx {

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
class IteratorOperation {
public:
	ResultIt<T, internal::FilteredIteratorImpl<T, BaseIt>> filter(std::function<bool(const T&)>);
};

}

#include <fmrcxx/impl/IteratorOperation.hpp>

#endif
