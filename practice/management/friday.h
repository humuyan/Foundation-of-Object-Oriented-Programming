#pragma once
#include "day.h"

class Friday: public Day {
	public:
		Friday(const int &month, const int &day, const string &name) : Day(month, day, name) {}
		virtual void print() {
			Day::print();
			if (plans.empty()) {
				cout << "Friday is Free :)" << endl;
			} else {
				cout << "Friday is Busy :(" << endl;
			}
		}
};
