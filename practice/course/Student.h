#pragma once
#include "Person.h"
#include <bits/stdc++.h>
using namespace std;

class Student: public Person {
	private:
		int score;
	public:
		Student(const string &_name, const string &_info, const int &_score);
		~Student();
		string getInfo() const;
};
