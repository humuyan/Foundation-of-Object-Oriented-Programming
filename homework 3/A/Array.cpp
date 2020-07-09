#include "Array.h"
#include <bits/stdc++.h>
using namespace std;

Array::Array(int len) : n(len) {
	a = new Node[len];
}
Array::~Array() {
	delete[] a;
}
Node &Array::operator[](const int &i) {
	return a[i];
}
void Array::update(const int &q, const int &r) {
	a[q] = a[r];
}
void Array::swap(const int &q, const int &r) {
	Node t = move(a[q]);
	a[q] = move(a[r]);
	a[r] = move(t);
}
void Array::insert(const int &q, const int &r) {
	for (int i = n-1; i >= q+1; i--) {
		a[i] = move(a[i-1]);
	}
	a[q] = move(Node(r));
}
