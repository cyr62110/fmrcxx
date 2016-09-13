#ifndef FMRCXX_STDITERATOR_H_
#define FMRCXX_STDITERATOR_H_

#include <fmrcxx/Iterator.h>

namespace fmrcxx {

template <typename T, typename It>
class StdIterator : public Iterator<T> {
public:
	StdIterator(It&& start, It&& end);

	bool fullyConsumed();

	T& next();
private:
	It current;
	It end;
};

}

#include <fmrcxx/impl/StdIterator.hpp>

#endif
