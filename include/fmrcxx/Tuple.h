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
	Key getKey() const;

	/**
	 * \brief Return the value
	 */
	Value getValue() const;
private:
	Key key;
	Value value;
};

}

#include <fmrcxx/impl/Tuple.hpp>

#endif
