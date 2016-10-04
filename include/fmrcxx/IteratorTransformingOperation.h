#ifndef FMRCXX_ITERATORTRANSFORMINGOPERATION_H_
#define FMRCXX_ITERATORTRANSFORMINGOPERATION_H_

#include <cstddef>
#include <functional>

#include <fmrcxx/internal/FilteredIterator.h>
#include <fmrcxx/internal/MappingIterator.h>
#include <fmrcxx/internal/LimitingIterator.h>
#include <fmrcxx/internal/SkippingIterator.h>
#include <fmrcxx/internal/EachingIterator.h>
#include <fmrcxx/internal/CopyingIterator.h>

namespace fmrcxx {

/**
 * \brief
 * \tparam T
 * \tparam ResultIt Type of iterator
 * \tparam BaseIt
 *
 *
 */
template <typename T, template<typename, typename> class ResultIt, typename BaseIt>
class IteratorTransformingOperation {
public:
	ResultIt<T, internal::FilteredIterator<T, BaseIt>> filter(std::function<bool(const T&)> filterFunction);

	template <typename O> // FIXME add enable if to not enable if O is a pointer or an array
	ResultIt<O, internal::MappingIterator<O, T, BaseIt, false>> map(std::function<O(T&)> mapFunction);

	template <typename O>
	ResultIt<O, internal::MappingIterator<O, T, BaseIt, true>> map(std::function<O*(T&)> mapFunction);

	ResultIt<T, internal::LimitingIterator<T, BaseIt>> limit(std::uint32_t limit);

	ResultIt<T, internal::SkippingIterator<T, BaseIt>> skip(std::uint32_t skip);

	ResultIt<T, internal::EachingIterator<T, BaseIt>> each(std::function<void(T&)> eachFunction);

	ResultIt<T, internal::CopyingIterator<T, BaseIt>> copy();
};

}

#include <fmrcxx/impl/IteratorTransformingOperation.hpp>

#endif
