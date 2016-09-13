#ifndef FMRCXX_RANGE_H_
#define FMRCXX_RANGE_H_

#include <fmrcxx/Iterator.h>
#include <fmrcxx/IteratorOperation.h>

namespace fmrcxx {

/**
 * \brief
 */
template <typename T>
class Range : public Iterator<T>, public IteratorOperation<T, Iterator, Range<T>> {
public:
	Range(T start, T end, T increment = 1);
	Range(Range&& rhs);

	bool fullyConsumed();
	T& next();
private:
	T previous;
	T current;
	T end;
	T increment;
};

}

#include <fmrcxx/impl/Range.hpp>

#endif
