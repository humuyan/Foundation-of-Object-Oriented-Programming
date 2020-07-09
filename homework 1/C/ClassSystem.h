#pragma once
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class ClassSystem {
	private:
		int classNumber;
		map<string, int> h;
		vector<string> name;

	public:
		ClassSystem();
		void addStudent(Student);
		void addClassNumber();
		void signIn(string);
		Student getStudentById(int);
		Student getStudentByName(string);
};
