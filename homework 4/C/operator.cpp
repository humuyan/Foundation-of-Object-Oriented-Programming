#include "operator.h"

PlusOperator::PlusOperator(const string &name, const string &operation_type, Node *x1, Node *x2) : OperationNodeTwo(name, x1, x2) {
	if (operation_type == "+") {
		neg = 1;
	} else {
		neg = -1;
	}
}
void PlusOperator::UpdateValue() {
	value_ = input1->value() + neg * input2->value();
}
