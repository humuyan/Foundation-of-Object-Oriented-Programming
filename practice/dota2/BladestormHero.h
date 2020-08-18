#pragma once
#include "SkilledHero.h"

class BladestormHero : public SkilledHero {
	public:
		BladestormHero(Hero *last) {
			last->getSkill(skill);
			++skill["Bladestorm"];
		}
};
