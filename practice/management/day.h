#pragma once
#include "plan.h"

class Day {
	protected:
		int month, day;
		string name;
		vector<Plan> plans;

	public:
		Day(const int &month, const int &day, const string &name) : month(month), day(day), name(name) {} 
		bool insert(const Plan &x) {
			if (x.month != month || x.day != day) {
				return false;
			}
			plans.push_back(x);
			return true;
		}
		virtual void print() {
			cout << month << '/' << day << ' ' << name;
			if (plans.empty()) {
				cout << " Today is Free" << endl;
			} else {
				cout << " Today's Plan:" << endl;
				for (Plan x: plans) {
					cout << x.content << endl;
				}
			}
		}
};
