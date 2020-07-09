#include "motor.h"

Motor::Motor(int wheelNumber, string engineName) : Vehicle(wheelNumber, engineName, true){
	cout << "Finish building a motor with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}
void Motor::describe() {
	cout << "A motor with " << w.get_num() << " wheels and a " << e.get_name() << " engine." << endl;
}
void Motor::sell() {
	cout << "A motor is sold!" << endl;
}
