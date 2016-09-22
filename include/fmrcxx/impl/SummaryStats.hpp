#include <fmrcxx/SummaryStats.h>

namespace fmrcxx {

template <typename T, typename ST, typename AT>
class SummaryStats<T, ST, AT>::Impl {
public:
	Impl() : empty(true), count(0), sum(), min(), max() {}

	bool empty;
	unsigned long count;
	ST sum;
	T min;
	T max;
};

template <typename T, typename ST, typename AT>
void SummaryStats<T, ST, AT>::accumulate(const T& value) {
	this->impl.count ++;
	if (this->impl.empty) {
		this->impl.empty = false;
		this->impl.sum = value;
		this->impl.min = value;
		this->impl.max = value;
	} else {
		this->impl.sum += value;
		if (this->impl.min > value) {
			this->impl.min = value;
		}
		if (this->impl.max < value) {
			this->impl.max = value;
		}
	}
}

template <typename T, typename ST, typename AT>
unsigned long SummaryStats<T, ST, AT>::getCount() const noexcept {
	return this->impl.count;
}

template <typename T, typename ST, typename AT>
const T& SummaryStats<T, ST, AT>::getMin() const noexcept {
	return this->impl.min;
}

template <typename T, typename ST, typename AT>
const T& SummaryStats<T, ST, AT>::getMax() const noexcept {
	return this->impl.max;
}

template <typename T, typename ST, typename AT>
const ST& SummaryStats<T, ST, AT>::getSum() const noexcept {
	return this->impl.sum;
}

template <typename T, typename ST, typename AT>
AT SummaryStats<T, ST, AT>::getAverage() const {
	return AT(this->impl.sum) / this->impl.count;
}

}
