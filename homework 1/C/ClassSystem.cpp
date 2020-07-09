#include "ClassSystem.h"
#include "Student.h"

ClassSystem::ClassSystem() {
	classNumber = 0, h.clear(), name.clear();
}
void ClassSystem::addStudent(Student stu) {
	name.push_back(stu.getName());
	h[stu.getName()] = 0;
}
void ClassSystem::addClassNumber() {
	++classNumber;
}
void ClassSystem::signIn(string name) {
	++h[name];
}
Student ClassSystem::getStudentById(int id) {
	return Student(name[id], h[name[id]], classNumber-h[name[id]]);
}
Student ClassSystem::getStudentByName(string name) {
	return Student(name, h[name], classNumber-h[name]);
}
