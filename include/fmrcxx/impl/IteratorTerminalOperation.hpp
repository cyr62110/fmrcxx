#ifndef FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_
#define FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_

#include <fmrcxx/IteratorTerminalOperation.h>

namespace fmrcxx {

template <typename T, typename It>
void IteratorTerminalOperation<T, It>::forEach(std::function<void(T&)> function) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		function(it.next());
	}
}

}

#endif
