#include "NoMoveTestObject.h"

NoMoveTestObject::NoMoveTestObject(int value) :
	value(value) {
}

NoMoveTestObject::NoMoveTestObject(const NoMoveTestObject& rhs) :
	value(rhs.value) {
}

int NoMoveTestObject::getValue() {
	return this->value;
}

