#include "Course.h"

Course::Course(const int &_studentCnt, const string &_name) : name(_name) {
	cout << "constructing Course: " << name << endl;
}
Course::~Course() {
	delete teacher;
	for (auto x: students) {
		delete x;
	}
	cout << "destructing Course: " << name << endl;
}
void Course::addTeacher(const string &name) {
	teacher = new Teacher(name);
}
void Course::addStudent(const string &name, const int &score, const string &info) {
	students.push_back(new Student(name, info, score));
}
string Course::getSubject() const {
	return name;
}
Student *Course::getStudent(const string &name) const {
	for (auto x: students) {
		if (x->getName() == name) {
			return x;
		}
	}
	return nullptr;
}
Teacher *Course::getTeacher() const {
	return teacher;
}