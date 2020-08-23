#pragma once
#include "what.h"
#include <bits/stdc++.h>
using namespace std;

class Alien: public WhatCanMotion, public WhatCanSpeak  {
	private:
		string name;

	public:
		Alien(const string &name) : name(name) {}
		virtual void speak() {
			cout << name << " is speaking" << endl;
		}
		virtual void motion() {
			cout << name << " is moving" << endl;
		}
		virtual void stop() {
			cout << name << " stops" << endl;
		}
};
