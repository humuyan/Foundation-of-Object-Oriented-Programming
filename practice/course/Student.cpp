#include "Student.h"

Student::Student(const string &_name, const string &_info, const int &_score) : Person(_name, _info), score(_score) {
	cout << "constructing Student " << _name << endl;
}
Student::~Student() {
	cout << "destructing Student " << getName() << endl;
}
string Student::getInfo() const {
	return "Student " + Person::getInfo() + " Score:" + to_string(score);
}
