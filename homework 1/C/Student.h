#pragma once
#include <bits/stdc++.h>
using namespace std;

class Student {
	private:
		string name;
		int presentTimes, absentTimes;

	public:
		Student(string);
		Student(string, int, int);
		string getName();
		int getPresentTimes();
		int getAbsentTimes();
};
