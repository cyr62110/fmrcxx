#ifndef INCLUDE_FMRCXX_SUMMARYSTATS_H_
#define INCLUDE_FMRCXX_SUMMARYSTATS_H_

namespace fmrcxx {

/**
 * \brief Provides method to easily compute basic statistics.
 * \tparam T Type of item. Must be arithmetic.
 * \tparam ST Type to use to compute the sum.
 * \tparam AT Type to use to compute the average.
 */
template <typename T, typename ST = T, typename AT = double>
class SummaryStats {
public:
	/**
	 * \internal
	 * \brief Accumulate a new value and recompute all statistics.
	 */
	void accumulate(const T& value);

	/**
	 * \brief Return the number of accumulated value.
	 */
	unsigned long getCount() const noexcept;

	/**
	 * \brief Return the minimum accumulated value.
	 */
	const T& getMin() const noexcept;

	/**
	 * \brief Return the maximum accumulated value.
	 */
	const T& getMax() const noexcept;

	/**
	 * \brief Return the sum of all accumulated value.
	 */
	const ST& getSum() const noexcept;

	/**
	 * \brief Return the average of all accumulated value.
	 */
	AT getAverage() const;

	/**
	 * \brief Return the variance of all accumulated value
	 *
	 *
	 */
	//FIXME AT getVariance() const;
	// FIXME Implements online algorithm of https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance

private:
	class Impl;
	Impl impl;
};

}

#include <fmrcxx/impl/SummaryStats.hpp>

#endif
