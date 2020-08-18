#pragma once
#include <list>
#include <memory>

class MyList
{
private:
	std::shared_ptr< std::list<int> > pt; // a pointer to the real container
	std::list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	std::list<int>::iterator forward(int pos) const{
		// count from 'left', find the element at position 'pos'.
		auto now = left;
		while(pos--) now++;
		return now;
	}

public:
	MyList(): pt(new std::list<int>()){
		left = pt->begin();
		right = pt->end();
		// Actually, left = right = pt->end(), because there is no element in the list.
	}

	void append(int i){
		bool dec = (left == pt->end());
		pt->insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		if (dec) {
			--left;
		}
		// DEBUG !! Why I can't insert i??
	}

	int &operator[](int pos) const{
		return *forward(pos); // access the element at the 'pos'
	}

	MyList operator()(const int &l, const int &r) const {
		MyList ret;
		ret.pt = pt;
		ret.left = forward(l), ret.right = forward(r);
		return ret;
	}

	friend std::ostream &operator<<(std::ostream &out, const MyList &x){
		out << "[";
		if (x.left != x.right){
			auto now = x.left;
			out << *now;
			now ++;
			for(; now != x.right; now++){
				out << "," << *now;
			}
		}
		out << "]";
		return out;
	}

};
