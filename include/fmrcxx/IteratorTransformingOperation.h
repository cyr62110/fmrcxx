#ifndef FMRCXX_ITERATORTRANSFORMINGOPERATION_H_
#define FMRCXX_ITERATORTRANSFORMINGOPERATION_H_

#include <fmrcxx/internal/FilteredIterator.h>
#include <cstddef>
#include <functional>


namespace fmrcxx {

template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
class IteratorTransformingOperation {
public:
	ResultIt<T, internal::FilteredIterator<T, BaseIt>> filter(std::function<bool(const T&)>);
};

}

#include <fmrcxx/impl/IteratorTransformingOperation.hpp>

#endif
