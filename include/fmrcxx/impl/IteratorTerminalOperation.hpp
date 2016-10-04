#ifndef FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_
#define FMRCXX_IMPL_ITERATORTERMINALOPERATION_H_

#include <fmrcxx/IteratorTerminalOperation.h>
#include <fmrcxx/exception/UnsupportedContainerTypeException.h>

namespace fmrcxx {

template <typename T, typename It>
unsigned long IteratorTerminalOperation<T, It>::count() {
	unsigned long count = 0;
	It& it = *((It*) this);
	for (count = 0; !it.fullyConsumed(); count++) {
		it.next();
	}
	return count;
}

template <typename T, typename It>
void IteratorTerminalOperation<T, It>::forEach(std::function<void(T&)> function) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		function(it.next());
	}
}

template <typename T, typename It> template <typename Acc>
Acc IteratorTerminalOperation<T, It>::reduce(Acc startValue, std::function<Acc(Acc&, const T&)> reduceFunction) {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		return startValue;
	}
	Acc value = reduceFunction(startValue, it.next());
	while (!it.fullyConsumed()) {
		value = reduceFunction(value, it.next());
	}
	return value;
}

template <typename T, typename It>
bool IteratorTerminalOperation<T, It>::allMatch(std::function<bool(const T&)> condition) {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		throw exception::OperationOnFullyConsumedIteratorException();
	}
	bool result = true;
	while (result && !it.fullyConsumed()) {
		result = condition(it.next());
	}
	return result;
}

template <typename T, typename It>
bool IteratorTerminalOperation<T, It>::anyMatch(std::function<bool(const T&)> condition) {
	It& it = *((It*) this);
	if (it.fullyConsumed()) {
		throw exception::OperationOnFullyConsumedIteratorException();
	}
	bool result = false;
	while (!result && !it.fullyConsumed()) {
		result = condition(it.next());
	}
	return result;
}

template <typename T, typename It>
bool IteratorTerminalOperation<T, It>::noneMatch(std::function<bool(const T&)> condition) {
	return !anyMatch(std::move(condition));
}

template <typename T, typename It> template <typename Acc>
void IteratorTerminalOperation<T, It>::reduce(Acc& accumulator, std::function<void(Acc&, const T&)> reduceFunction) {
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		reduceFunction(accumulator, it.next());
	}
}

template <typename T, typename It> template <template <typename...> class Container, typename... TPs>
Container<T, TPs...> IteratorTerminalOperation<T, It>::to() {
	Container<T, TPs...> container;
	It& it = *((It*) this);
	while (!it.fullyConsumed()) {
		appendToContainer(container, std::move(it.next()));
	}
	return container;
}

template <typename T, typename It> template <template <typename...> class Container, typename... TPs>
void IteratorTerminalOperation<T, It>::appendToContainer(Container<T, TPs...>& container, T&& obj) {
	throw exception::UnsupportedContainerTypeException();
}

template <typename T, typename It> template <typename... TPs>
void IteratorTerminalOperation<T, It>::appendToContainer(std::vector<T, TPs...>& container, T&& obj) {
	container.emplace_back(std::move(obj));
}

template <typename T, typename It> template <template <typename...> class Container, typename pT, typename... TPs>
Container<pT, TPs...> IteratorTerminalOperation<T, It>::copyTo() {
	It& it = *((It*) this);
	Container<pT, TPs...> container;
	while (!it.fullyConsumed()) {
		T* pNext = &it.next();
		if (it.ownItem() && it.areItemAllocatedDynamically()) {
			it.releaseOwnership();
		} else {
			pNext = new T(*pNext);
		}
		appendToContainer(container, pNext);
	}
	return container;
}

template <typename T, typename It> template <template <typename...> class Container, typename pT, typename... TPs>
void IteratorTerminalOperation<T, It>::appendToContainer(Container<pT, TPs...>& container, T* obj) {
	throw exception::UnsupportedContainerTypeException();
}

template <typename T, typename It> template <typename pT, typename... TPs>
void IteratorTerminalOperation<T, It>::appendToContainer(std::vector<pT, TPs...>& container, T* obj) {
	container.emplace_back(obj);
}

}

#endif
