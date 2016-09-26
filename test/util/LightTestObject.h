#ifndef UTIL_LIGHTTESTOBJECT_H_
#define UTIL_LIGHTTESTOBJECT_H_

class LightTestObject {
public:
	LightTestObject(int value);
	LightTestObject(const LightTestObject& rhs);
	LightTestObject(LightTestObject&& rhs);

	~LightTestObject();

	static int nbTimeConstructorCalled;
	static int nbTimeCopyConstructorCalled;
	static int nbTimeMoveConstructorCalled;

	static int nbTimeDestructorCalled;

	static void resetCounters();

	int getValue() const;
private:
	int value;
};

#endif
