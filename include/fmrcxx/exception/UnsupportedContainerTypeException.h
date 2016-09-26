#ifndef FMRCXX_EXCEPTION_UNSUPPORTEDCONTAINERTYPEEXCEPTION_H_
#define FMRCXX_EXCEPTION_UNSUPPORTEDCONTAINERTYPEEXCEPTION_H_

#include <exception>

namespace fmrcxx {
namespace exception {

/**
 * \brief Exception thrown if the items cannot be inserted into the container.
 */
class UnsupportedContainerTypeException : public std::exception {
public:
	virtual const char* what() const noexcept {
		return "Items cannot be inserted into container.";
	}
};

}}

#endif
