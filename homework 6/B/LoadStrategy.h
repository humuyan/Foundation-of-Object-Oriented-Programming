#pragma once
#include <bits/stdc++.h>
using namespace std;

class LoadStrategy {								
	public:
		virtual float load() = 0;
};


class NumberLoadStrategy : public LoadStrategy {	
	public:
		virtual float load() {
			int money;
			cin >> money;
			return money;
		}
};

class WordLoadStrategy : public LoadStrategy {	
	private:
		static const string num[10];
	public:
		virtual float load() {
			int money = 0;
			string s;
			for (cin >> s; s != "#"; cin >> s) {
				for (int i = 0; i < 10; ++i) {
					if (s == num[i]) {
						money = money * 10 + i;
						break;
					}
				}
			}
			return money;
		}
};
const string WordLoadStrategy::num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};