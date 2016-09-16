#include "LightTestObject.h"

int LightTestObject::nbTimeConstructorCalled = 0;
int LightTestObject::nbTimeCopyConstructorCalled = 0;
int LightTestObject::nbTimeMoveConstructorCalled = 0;
int LightTestObject::nbTimeDestructorCalled = 0;

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
