#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
int Example::cnt = 0;

Example::Example(int data) {
	// (3)
	this->data = data;
	id = ++cnt;
	printf("Example #%d is created\n", id);
}

void Example::getData() {
	// (4)
	printf("The data of Example #%d is %d\n", id, data);
}

Example::~Example() {
	// (5)
	printf("Example #%d is destroyed\n", id);
}
