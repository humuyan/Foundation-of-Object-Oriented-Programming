#pragma once

class PayStrategy {								
	public:
		virtual float pay(const float&) = 0;
};


class NormalStrategy : public PayStrategy {	
	public:
		virtual float pay(const float &money) {
			return money;
		}
};

class RebateStrategy : public PayStrategy {	
	public:
		virtual float pay(const float &money) {
			return money * 0.38;
		}
};

class ReturnStrategy : public PayStrategy {	
	public:
		virtual float pay(const float &money) {
			return (money >= 25) ? money - 10 : money;
		}
};
