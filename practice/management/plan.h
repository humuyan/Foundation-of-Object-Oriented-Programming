#pragma once
#include <bits/stdc++.h>
using namespace std;

class Plan {
	private:
		int month, day;
		string content;

	public:
		Plan(const int &month, const int &day, const string &content) : month(month), day(day), content(content) {}
		friend class Day;
};
