#ifndef FMRCXX_IMPL_ITERATORARITHMETICTERMINALOPERATION_HPP_
#define FMRCXX_IMPL_ITERATORARITHMETICTERMINALOPERATION_HPP_

#include <fmrcxx/IteratorArithmeticTerminalOperation.h>
#include <fmrcxx/exception/OperationOnFullyConsumedIteratorException.h>

namespace fmrcxx {

template <typename T, typename It> template <typename ST>
ST IteratorArithmeticTerminalOperation<T, It>::sum() {
	It& it = *((It*) this);
	ST s{};
	while (!it.fullyConsumed()) {
		s += it.next();
	}
	return s;
}

template <typename T, typename It>
T IteratorArithmeticTerminalOperation<T, It>::min() {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		throw exception::OperationOnFullyConsumedIteratorException();
	}
	T min(it.next());
	while (!it.fullyConsumed()) {
		T& value = it.next();
		if (min > value) {
			min = value;
		}
	}
	return min;
}

template <typename T, typename It>
T IteratorArithmeticTerminalOperation<T, It>::max() {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		throw exception::OperationOnFullyConsumedIteratorException();
	}
	T max(it.next());
	while (!it.fullyConsumed()) {
		T& value = it.next();
		if (max < value) {
			max = value;
		}
	}
	return max;
}

template <typename T, typename It> template <typename ST, typename AT>
AT IteratorArithmeticTerminalOperation<T, It>::average() {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		throw exception::OperationOnFullyConsumedIteratorException();
	}
	ST sum{};
	unsigned long count = 0;
	while (!it.fullyConsumed()) {
		sum = sum + it.next();
		count ++;
	}
	return static_cast<AT>(sum) / count;
}

template <typename T, typename It> template <typename ST, typename AT>
const SummaryStats<T, ST, AT> IteratorArithmeticTerminalOperation<T, It>::stats() {
	SummaryStats<T, ST, AT> stats;
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		stats.accumulate(it.next());
	}
	return stats;
}

}

#endif
