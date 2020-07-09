#pragma once
#include "operation.h"

class PlusOperator : public OperationNodeTwo {
	private:
		int neg;
	public:
		PlusOperator(const string &name, const string &operation_type, Node *x1, Node *x2);
		void UpdateValue() override;
};
