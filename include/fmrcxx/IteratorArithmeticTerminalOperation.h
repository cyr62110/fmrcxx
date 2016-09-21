#ifndef FMRCXX_ITERATORARITHMETICTERMINALOPERATION_H_
#define FMRCXX_ITERATORARITHMETICTERMINALOPERATION_H_

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
 * - move constructor
 * - operator +
 * - operator /
 *
 */
template <typename T, typename It>
class IteratorArithmeticTerminalOperation {
public:
	/**
	 * \brief Return the sum of all items in the iterator.
	 */
	T sum();
};

}

#include <fmrcxx/impl/IteratorArithmeticTerminalOperation.hpp>

#endif
