#ifndef FMRCXX_EXCEPTION_OPERATIONONFULLYCONSUMEDITERATOREXCEPTION_H_
#define FMRCXX_EXCEPTION_OPERATIONONFULLYCONSUMEDITERATOREXCEPTION_H_

#include <exception>

namespace fmrcxx {
namespace exception {

/**
 * \brief Exception thrown if the operation do not supports to be called on fully consumed iterator
 */
class OperationOnFullyConsumedIteratorException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "This operation cannot be called on fully consumed iterator";
	}
};

}}

#endif
