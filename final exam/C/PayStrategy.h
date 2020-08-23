#pragma once
#include <bits/stdc++.h>
#include "OccupationStrategy.h"
using namespace std;

class PayStrategy {								
	public:
		virtual double pay(string name, double money) = 0;
};


class NormalStrategy : public PayStrategy {	
	public:
		virtual double pay(string name, double money) {
			return money;
		}
};

class SwiftStrategy : public PayStrategy {	
	public:
		virtual double pay(string name, double money) {
			if (money < 10000+Eps) {
				return money - 10;
			} else {
				return money - min(20.0, money/1000);
			}
		}
};

class BitcoinStrategy : public PayStrategy {	
	public:
		virtual double pay(string name, double money) {
			return money - (name.size() + 8) * 0.01;
		}
};
