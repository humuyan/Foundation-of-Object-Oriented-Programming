#pragma once
#include "Person.h"
#include <bits/stdc++.h>
using namespace std;

class Teacher: public Person {
	public:
		Teacher(const string &_name);
		~Teacher();
};
