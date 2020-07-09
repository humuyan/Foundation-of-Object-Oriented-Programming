#pragma once
#include "Node.h"

class Array {
	private:
		Node *a;
		int n;

	public:
		Array(int len);
		~Array();
		Node &operator[](const int &i);
		void update(const int &q, const int &r);
		void swap(const int &q, const int &r);
		void insert(const int &q, const int &r);
};
