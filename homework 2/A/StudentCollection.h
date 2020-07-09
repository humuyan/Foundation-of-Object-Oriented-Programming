#pragma once
#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

class StudentCollection {
	private:
		vector<Student> stuList;
		map<string, int> h;

	public:
		void sortByScore();
		friend istream &operator>>(istream &in, StudentCollection &x);
		friend ostream &operator<<(ostream &out, const StudentCollection &x);
		Student operator[](const string &name);
};
