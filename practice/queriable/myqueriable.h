#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
class MyQueriable {
	private:
		vector<T> a;
	
	public:
		template<typename A, template<typename, typename = allocator<A>> class Container> friend MyQueriable<A> from(const Container<A> &arr);
		template<class A, int size> friend MyQueriable<A> from(A (&arr)[size]);
		MyQueriable where(function<bool(T)> f) const {
			MyQueriable<T> ret;
			for (T x: a) {
				if (f(x)) {
					ret.a.push_back(x);
				}
			}
			return ret;
		}
		MyQueriable apply(function<T(T)> f) const {
			MyQueriable<T> ret;
			for (T x: a) {
				ret.a.push_back(f(x));
			}
			return ret;
		}
		T sum() const {
			return accumulate(a.begin(), a.end(), 0);
		}
		auto begin() const {
			return a.begin();
		}
		auto end() const {
			return a.end();
		}
};
template<typename A, template<typename, typename = allocator<A>> class Container>
MyQueriable<A> from(const Container<A> &arr) {
	MyQueriable<A> ret;
	for (A x: arr) {
		ret.a.push_back(x);
	}
	return ret;
}
template<class A, int size>
MyQueriable<A> from(A (&arr)[size]) {
	MyQueriable<A> ret;
	for (int i = 0; i < size; ++i) {
		ret.a.push_back(arr[i]);
	}
	return ret;
}
