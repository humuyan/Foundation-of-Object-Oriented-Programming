#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
class MyQueriable {
	private:
		vector<T> base;
	public:
		unsigned size() const {
			return base.size();
		}
		T operator[](const int &index) const {
			return base[index];
		}
		MyQueriable<T> where(function<bool(T)> f) const {
			MyQueriable<T> ret;
			for (T x: base) {
				if (f(x)) {
					ret.base.push_back(x);
				}
			}
			return ret;
		}
		MyQueriable<T> apply(function<T(T)> f) const {
			MyQueriable<T> ret;
			for (T x: base) {
				ret.base.push_back(f(x));
			}
			return ret;
		}
		T sum() const {
			return accumulate(base.begin(), base.end(), 0);
		}
		template<class A> friend MyQueriable<A> from(const vector<A> &a);
		template<class A> friend MyQueriable<A> from(const list<A> &a);
};

template<class A>
MyQueriable<A> from(const vector<A> &a) {
	MyQueriable<A> ret;
	ret.base = a;
	return ret;
}
template<class A>
MyQueriable<A> from(const list<A> &a) {
	MyQueriable<A> ret;
	for (A x: a) {
		ret.base.push_back(x);
	}
	return ret;
}