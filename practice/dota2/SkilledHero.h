#pragma once
#include "Hero.h"

class SkilledHero : public Hero {
	protected:
		name2Level skill;
	
	public:
		void getSkill(name2Level &skillMap) {
			skillMap = skill;
		}
};
