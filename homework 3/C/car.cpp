#include "car.h"

Car::Car(int wheelNumber, string engineName) : Vehicle(wheelNumber, engineName, true) {
	cout << "Finish building a car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}
void Car::describe() {
	cout << "A car with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}
