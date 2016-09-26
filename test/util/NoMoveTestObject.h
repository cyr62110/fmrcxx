#ifndef UTIL_NOMOVETESTOBJECT_H_
#define UTIL_NOMOVETESTOBJECT_H_

class NoMoveTestObject {
public:
	NoMoveTestObject(int value);
	NoMoveTestObject(const NoMoveTestObject& rhs);
	NoMoveTestObject(NoMoveTestObject&& rhs) = delete;

	int getValue();
private:
	int value;
};

#endif
