#ifndef CONTAINER_H
#define CONTAINER_H
#include "BasicContainer.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using std::vector;
using std::map;

template<class A>
struct Point {
    Pos pos;
    A value;
    Point (Pos p, A v): pos(p), value(v) {}
};
template<class A>
inline bool cmp(const Point<A> &i, const Point<A> &j) {
    return (i.pos < j.pos);
}

template<class A, class C>
class Container : public BasicContainer<A> {
public:
    void insert(const Pos &p, const A &v) {};
    A* find(Pos p) { return NULL; };
};

template <class A>
class Container<A, vector<A> > : public BasicContainer<A> {
private:
    vector< Point<A> > base;
    bool sorted;
public:
    void insert(const Pos &p, const A &v) {
        base.push_back(Point<A>(p, v));
        sorted = false;
    }

    A* find(Pos p) {
        if (!sorted) {
            std::sort(base.begin(), base.end(), cmp<A>);
            sorted = true;
        }
        auto t = std::lower_bound(base.begin(), base.end(), (Point<A>){p, A()}, cmp<A>);
        if (t->pos == p) {
            return &t->value;
        } else {
            return NULL;
        }
    }
};

template<class A>
class Container<A, map<Pos, A>>: public BasicContainer<A> {
    private:
        map<Pos, A> base;
    
    public:
        void insert(const Pos &p, const A &v) {
            base[p] = v;
        }
        A* find(Pos p) {
            if (base.find(p) != base.end()) {
                return &base[p];
            } else {
                return NULL;
            }
        }
};

#endif
