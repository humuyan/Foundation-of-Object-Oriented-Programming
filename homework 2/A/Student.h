#pragma once
#include <bits/stdc++.h>
using namespace std;

class StudentCollection;

class Student {
	private:
		string name;
		int chineseScore, mathScore, englishScore, totalScore;

	public:
		Student(string s = "") : name(s), totalScore(0) {}
		friend bool operator<(const Student &i, const Student &j);
		friend ostream &operator<<(ostream &out, const Student &x);
		friend istream &operator>>(istream &in, StudentCollection &x);
};
