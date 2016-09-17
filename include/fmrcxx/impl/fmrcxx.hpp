#ifndef FMRCXX_IMPL_FMRCXX_HPP_
#define FMRCXX_IMPL_FMRCXX_HPP_

namespace fmrcxx {

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> iterateOver(Container<T>& container) {
	return StdContainerIterator<T, typename Container<T>::iterator>(container.begin(), container.end());
}

template <typename T, template <typename, typename...> class Container>
StdContainerIterator<T, typename Container<T>::iterator> reverseIterateOver(Container<T>& container) {
	return StdContainerIterator<T, typename Container<T>::iterator>(container.rbegin(), container.rend());
}

}

#endif
