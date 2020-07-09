#include <iostream>
#include "MyAnswer.h"
using namespace std;

#define Option_A auto testA = f1("testA", A("b", move(b)));
#define Option_B auto testB = f2(b);
#define Option_C auto testC = f3("testC", A("b", move(b)));
#define Option_D auto testD = f3("testD", A("b", move(b)));
#define Option_E auto& testE = f4(f);
#define Option_F auto testF = f5("testF", move(b));

class A {
public:
	string name;
	A(string s) : name(s) {
		cout << "A constructing..." << name << endl;
	}
	A(string s, const A &a) : name(s) {
		cout << "A copy constructing..." << name << endl;
	}
	A(string s, A&& a) : name(s) {
		cout << "A move constructing..." << name << endl; 
	}
	~A(){
		cout << "A destructing..." << name << endl;
	}
};

class B {
private:
	static A data1;
	A data2;
public:
	string name;
	B(string s) : name(s), data2(s+".data2") {
		cout << "B constructing..." << name << endl;
	}
	~B(){
		cout << "B destructing..." << name << endl;
	}
};

A B::data1("B::data1");

A f1(string name, A b) {
	cout << "------after call------" << endl;
	A f = A("f", move(b));
	cout << "------before return------" << endl;
	f.name = name;
	return f;
}

A* f2(A& b) {
	cout << "------after call------" << endl;
	A* f = &b;
	cout << "------before return------" << endl;
	return f;
}


A f3(string name, A b) {
	cout << "------after call------" << endl;
	static A f("f");
	cout << "------before return------" << endl;
	return A(name, f);
}

A& f4(A* b) {
	cout << "------after call------" << endl;
	A *f = b;
	cout << "------before return------" << endl;
	return *f;
}

A f5(string name, A&& b) {
	cout << "------after call------" << endl;
	A f("f", b);
	cout << "------before return------" << endl;
	f.name = name;
	return f;
}

void work()
{
	cout << "=======entering work=======" << endl;
	A b("b");
	B t("t");
	
	A f[2] = {A("f[0]"), A("f[1]")};
	
	cout << "------before call------" << endl;
	Answer1 // (1)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer2 //(2)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer3 //(3)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer4 //(4)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer5 //(5)
	cout << "------after return------" << endl << endl;
	
	cout << "------before call------" << endl;
	Answer6 //(6)
	cout << "------after return------" << endl << endl;
	
	cout << "=======exiting work=======" << endl;
}

int main() {
	cout << "=======entering main=======" << endl;
	work();
	cout << "=======exiting main=======" << endl;
	return 0;
}
