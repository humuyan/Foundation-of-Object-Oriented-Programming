#include "Teacher.h"

Teacher::Teacher(const string &_name) : Person(_name, "") {
	cout << "constructing Teacher " << _name << endl;
}
Teacher::~Teacher() {
	cout << "destructing Teacher " << getName() << endl;
}
