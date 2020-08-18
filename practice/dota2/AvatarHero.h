#pragma once
#include "SkilledHero.h"

class AvatarHero : public SkilledHero {
	public:
		AvatarHero(Hero *last) {
			last->getSkill(skill);
			++skill["Avatar"];
		}
};
