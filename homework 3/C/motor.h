#pragma once
#include "vehicle.h"

class Motor: private Vehicle {
	public:
		Motor(int wheelNumber, string engineName);
		void describe();
		void sell();
};
