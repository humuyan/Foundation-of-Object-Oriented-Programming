#include "Student.h"

Student::Student(string name) {
	this->name = name;
}
Student::Student(string name, int presentTimes, int absentTimes) {
	this->name = name, this->presentTimes = presentTimes, this->absentTimes = absentTimes;
}
string Student::getName() {
	return name;
}
int Student::getAbsentTimes() {
	return absentTimes;
}
int Student::getPresentTimes() {
	return presentTimes;
}
