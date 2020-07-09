#pragma once
#include <bits/stdc++.h>
#include "wheel.h"
#include "engine.h"
using namespace std;

class Vehicle {
	protected:
		Engine e;
		Wheel w;

	public:
		Vehicle(int wheelNumber, string engineName, bool mute = false);
		void describe();
};
