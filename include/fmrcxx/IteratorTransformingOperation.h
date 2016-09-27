#ifndef FMRCXX_ITERATORTRANSFORMINGOPERATION_H_
#define FMRCXX_ITERATORTRANSFORMINGOPERATION_H_

#include <cstddef>
#include <functional>

#include <fmrcxx/internal/FilteredIterator.h>
#include <fmrcxx/internal/MappingIterator.h>
#include <fmrcxx/internal/LimitingIterator.h>

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
};

}

#include <fmrcxx/impl/IteratorTransformingOperation.hpp>

#endif
