#ifndef FMRCXX_EXCEPTION_NEXTOPERATIONONFULLYCONSUMEDITERATOREXCEPTION_H_
#define FMRCXX_EXCEPTION_NEXTOPERATIONONFULLYCONSUMEDITERATOREXCEPTION_H_

#include <exception>

namespace fmrcxx {
namespace exception {

/**
 * \brief Exception thrown when next is called on a fully consumed collection
 */
class NextOperationOnFullyConsumedIteratorException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "next() called on a fully consumed iterator";
	}
};

}}

#endif
