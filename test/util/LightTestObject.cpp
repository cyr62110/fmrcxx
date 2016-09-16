#include "LightTestObject.h"

LightTestObject::LightTestObject(int value) :
	value(value) {
	nbTimeConstructorCalled ++;
}

LightTestObject::LightTestObject(LightTestObject& rhs) :
	value(rhs.value) {
	nbTimeCopyConstructorCalled ++;
}

LightTestObject::LightTestObject(LightTestObject&& rhs) :
	value(rhs.value) {
	nbTimeMoveConstructorCalled ++;
}

LightTestObject::~LightTestObject() {
	nbTimeDestructorCalled ++;
}

void LightTestObject::resetCounters() {
	nbTimeConstructorCalled = 0;
	nbTimeCopyConstructorCalled = 0;
	nbTimeMoveConstructorCalled = 0;
	nbTimeDestructorCalled = 0;
}
