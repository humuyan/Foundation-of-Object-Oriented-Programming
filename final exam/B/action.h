#pragma once
#include "animal.h"
#include <bits/stdc++.h>
using namespace std;

void action(Animal* animal, vector<Dog> &dogzone, vector<Bird> &birdzone) {
	Dog *dog = dynamic_cast<Dog*>(animal);
	Bird *bird = dynamic_cast<Bird*>(animal);
	if (dog) {
		dogzone.push_back(move(*dog));
	} else {
		birdzone.push_back(move(*bird));
	}
}
