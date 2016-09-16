#ifndef FMRCXX_ITERATORTRANSFORMINGOPERATION_H_
#define FMRCXX_ITERATORTRANSFORMINGOPERATION_H_

#include <cstddef>
#include <functional>

#include <fmrcxx/internal/FilteredIterator.h>

namespace fmrcxx {

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
class IteratorTransformingOperation {
public:
	ResultIt<T, internal::FilteredIterator<T, BaseIt>> filter(std::function<bool(const T&)>);
};

}

#include <fmrcxx/impl/IteratorTransformingOperation.hpp>

#endif
