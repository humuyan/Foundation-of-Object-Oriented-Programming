#pragma once
#include <bits/stdc++.h>
using namespace std;

class Animal {
	protected:
		string name;
	
	public:
		Animal(const string &s) : name(s) {}
		virtual ~Animal() {}
		virtual void speak() = 0;
		virtual void swim() = 0;
		void action() {
			speak(), swim();
		}
};
