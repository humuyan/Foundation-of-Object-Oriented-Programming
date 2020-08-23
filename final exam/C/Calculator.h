#pragma once
#include "OccupationStrategy.h"
#include "PayStrategy.h"

class Calculator {								
	private:
		OccupationStrategy *calc;
		PayStrategy *give;
	
	public:
		Calculator(OccupationStrategy *calc, PayStrategy *give) : calc(calc), give(give) {}
		double getSalary(const double &base, const double &bonus, const double &level) {
			return calc->getSalary(base, bonus, level);
		}
		double pay(const string &name, const double &salary) {
			return give->pay(name, salary);
		}
};
