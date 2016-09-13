#ifndef FMRCXX_MAPITERATOR_H_
#define FMRCXX_MAPITERATOR_H_

#include <fmrcxx/Tuple.h>

namespace fmrcxx {

/**
 * \brief Class providing convenient method to iterate over a map.
 */
template <typename Key, typename Value>
class MapIterator {
public:
	/**
	 * \brief Default constructor
	 */
	MapIterator();

	/**
	 * \brief Move constructor
	 */
	MapIterator(MapIterator&& rhs);

	virtual ~MapIterator() = default;

	/**
	 * \brief Return true if the iterator has a next element.
	 */
	virtual bool fullyConsumed();

	/**
	 * \brief Return a reference to the next key-value pair in the map we iterate over.
	 */
	virtual Tuple<Key, Value> next() = 0;
private:
	bool moved;
};

}

#include <fmrcxx/impl/MapIterator.hpp>

#endif
