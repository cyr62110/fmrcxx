#ifndef FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_
#define FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_

#include <fmrcxx/IteratorTerminalOperation.h>

namespace fmrcxx {

template <typename T, typename It>
unsigned long IteratorTerminalOperation<T, It>::count() {
	unsigned long count = 0;
	It& it = *((It*) this);
	for (count = 0; !it.fullyConsumed(); count++) {
		it.next();
	}
	return count;
}

template <typename T, typename It>
void IteratorTerminalOperation<T, It>::forEach(std::function<void(T&)> function) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		function(it.next());
	}
}

template <typename T, typename It> template <typename Acc>
Acc IteratorTerminalOperation<T, It>::reduce(Acc startValue, std::function<Acc(Acc&, const T&)> reduceFunction) {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		return startValue;
	}
	Acc value = reduceFunction(startValue, it.next());
	while (!it.fullyConsumed()) {
		value = reduceFunction(value, it.next());
	}
	return value;
}

template <typename T, typename It> template <typename Acc>
void IteratorTerminalOperation<T, It>::reduce(Acc& accumulator, std::function<void(Acc&, const T&)> reduceFunction) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		reduceFunction(accumulator, it.next());
	}
}

}

#endif
