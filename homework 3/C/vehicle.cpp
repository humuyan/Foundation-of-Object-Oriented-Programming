#include "vehicle.h"

Vehicle::Vehicle(int wheelNumber, string engineName, bool mute /*= false*/) : e(engineName), w(wheelNumber) {
	if (!mute) {
		cout << "Finish building a vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
	}
}
void Vehicle::describe() {
	cout << "A vehicle with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}
