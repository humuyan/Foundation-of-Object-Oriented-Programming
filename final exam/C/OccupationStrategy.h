#pragma once

const double Eps = 1e-8;

class OccupationStrategy {								
	public:
		virtual double getSalary(double base, double bonus, double level) = 0;
};

class SalesmanStrategy : public OccupationStrategy {
	public:
		virtual double getSalary(double base, double bonus, double level) {
			double realBonus = 0;
			if (level > 60 - Eps && level < 70) {
				realBonus = 0.6 * bonus;
			} else {
				if (level > 70 - Eps && level < 80) {
					realBonus = 0.7 * bonus;
				} else {
					if (level > 80 - Eps) {
						realBonus = bonus;
					}
				}
			}
			return base + realBonus;
		}
};

class DeveloperStrategy : public OccupationStrategy {	
	public:
		virtual double getSalary(double base, double bonus, double level) {
			return base + bonus * level / 100;
		}
};
