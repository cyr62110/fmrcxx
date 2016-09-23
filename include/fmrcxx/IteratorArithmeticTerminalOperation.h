#ifndef FMRCXX_ITERATORARITHMETICTERMINALOPERATION_H_
#define FMRCXX_ITERATORARITHMETICTERMINALOPERATION_H_

#include <fmrcxx/SummaryStats.h>

namespace fmrcxx {

/**
 * \brief Provide terminal operations that can be executed on arithmetic items (integer, float, ...).
 * \tparam T Type of item in the iterator
 * \tparam It
 *
 * ## Arithmetic type
 *
 * Arithmetic types include all standard C++ arithmetic types: int, long, float, double, etc.
 * It also considered as arithmetic, all object that override the following method:
 * - copy constructor
 * - move constructor
 * - operator =
 * - operator +
 * - operator / (unsigned long)
 * - operator < (to compute max)
 * - operator > (to compute min)
 *
 */
template <typename T, typename It>
class IteratorArithmeticTerminalOperation {
public:
	/**
	 * \brief Return the sum of all values in the iterator.
	 * \tparam ST Type to use to sum all values
	 */
	template <typename ST = T>
	ST sum();

	/**
	 * \brief Return the minimum value in the iterator
	 * \throw OperationOnFullyConsumedIteratorException thrown if the iterator is fully consumed
	 */
	T min();

	/**
	 * \brief Return the maximum value in the iterator
	 * \throw OperationOnFullyConsumedIteratorException thrown if the iterator is fully consumed
	 */
	T max();

	/**
	 * \brief Return the maximum value in the iterator
	 * \tparam ST Type to use to sum all values
	 * \tparam AT Floating type to use for the average value
	 * \throw OperationOnFullyConsumedIteratorException thrown if the iterator is fully consumed
	 */
	template <typename ST = T, typename AT = double>
	AT average();

	/**
	 * \brief Return summary statistics of all item in the iterator.
	 */
	template <typename ST = T, typename AT = double>
	const SummaryStats<T, ST, AT> stats();
};

}

#include <fmrcxx/impl/IteratorArithmeticTerminalOperation.hpp>

#endif
