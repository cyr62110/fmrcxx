#ifndef FMRCXX_TUPLE_H_
#define FMRCXX_TUPLE_H_

namespace fmrcxx {

/**
 * \brief An immutable key-value pair
 */
template <typename Key, typename Value>
class Tuple {
public:
	/**
	 * \brief Default constructor
	 */
	Tuple(Key key, Value value);

	/**
	 * \brief Return the key
	 */
	Key getKey();

	/**
	 * \brief Return the value
	 */
	Value getValue();
private:
	Key key;
	Value value;
};

}

#include <fmrcxx/Tuple.hpp>

#endif
