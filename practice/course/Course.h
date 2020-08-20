#pragma once
#include "Teacher.h"
#include "Student.h"

class Course {
	private:
		vector<Student*> students;
		Teacher *teacher;
		string name;
	public:
		Course(const int &_studentCnt, const string &_name);
		~Course();
		void addTeacher(const string &name);
		void addStudent(const string &name, const int &score, const string &info);
		string getSubject() const;
		Student *getStudent(const string &name) const;
		Teacher *getTeacher() const;
};