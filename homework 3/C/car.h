#pragma once
#include "vehicle.h"

class Car: private Vehicle {
	public:
		Car(int wheelNumber, string engineName);
		void describe();
};
