#ifndef FMRCXX_INTERNAL_STDMAPITERATOR_H_
#define FMRCXX_INTERNAL_STDMAPITERATOR_H_

#include <fmrcxx/Iterator.h>
#include <fmrcxx/Tuple.h>

namespace fmrcxx {

template <typename Key, typename Value, typename It>
class StdMapIterator :
		public Iterator<Tuple<Key&, Value&>>,
		public IteratorTransformingOperation<Tuple<Key&, Value&>, Iterator, StdMapIterator<Key, Value, It>>,
		public IteratorTerminalOperation<Tuple<Key&, Value&>, StdMapIterator<Key, Value, It>> {
public:
	/**
	 * \brief Constructor that will take a begin and a end iterator
	 * \param begin Iterator to the beginning of the container
	 * \param end Iterator to the end of the container
	 */
	StdMapIterator(It&& begin, It&& end);

	StdMapIterator(StdMapIterator& rhs) = delete;

	/**
	 * \brief Move constructor
	 */
	StdMapIterator(StdMapIterator&& rhs);

	bool fullyConsumed();

	Tuple<Key&, Value&>& next();
private:
	It current;
	It end;

	bool first;
	std::uint8_t pTuple[sizeof(Tuple<Key&, Value&>)];
};

}

#include <fmrcxx/internal/impl/StdMapIterator.hpp>

#endif
