#pragma once
#include "LoadStrategy.h"
#include "PayStrategy.h"

class Calculator {								
	private:
		LoadStrategy *ls;
		PayStrategy *ps;
	public:
		Calculator(LoadStrategy *ls, PayStrategy* ps) : ls(ls), ps(ps) {}
		float load() {
			return ls->load();
		}
		float pay(const float &money) {
			return ps->pay(money);
		}
};