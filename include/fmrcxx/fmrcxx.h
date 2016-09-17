#ifndef FMRCXX_FMRCXX_H_
#define FMRCXX_FMRCXX_H_

#include <fmrcxx/internal/StdContainerIterator.h>
#include <vector>

#include <fmrcxx/Iterator.h>

namespace fmrcxx {

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> iterateOver(Container<T>& container);

template <typename T, template <typename, typename... Others> class Container>
StdContainerIterator<T, typename Container<T>::iterator> reverseIterateOver(Container<T>& container);

}

#include <fmrcxx/impl/fmrcxx.hpp>

#endif
