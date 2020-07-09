#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <bits/stdc++.h>
using namespace std;
template<class A, class C>
class Container : public BasicContainer<A>
{
	C base;
public:
	void insert(const A &x)
	{
		for(auto t = base.begin(); t != base.end(); ++t)
			if(*t > x)
			{
				base.insert(t, x);
				return;
			}
		base.insert(base.end(), x);
	}
	A find(int k)
	{
		auto t = base.begin();
		while(--k)
			++t;
		return *t;
	}
};

template<class A>
class Container<A, vector<A>>: public BasicContainer<A> {
	private:
		vector<A> base;
		bool sorted;
	public:
		void insert(const A &x) {
			base.push_back(x);
		}
		A find(int k) {
			if (!sorted) {
				sort(base.begin(), base.end());
				sorted = true;
			}
			return base[k-1];
		}
};

template<class A>
class Container<A, multiset<A>>: public BasicContainer<A> {
	private:
		multiset<A> base;
	public:
		void insert(const A &x) {
			base.insert(x);
		}
		A find(int k) {
			auto ret = base.begin();
			while (--k) {
				++ret;
			}
			return *ret;
		}
};
#endif
