#include "wrapper_counter.h"

class AbstractWrapper {
	string uid;
public:
	AbstractWrapper(string name) {
		uid = WrapperCounter::getUID(name);
	}
	virtual ~AbstractWrapper() = 0;
	virtual string type() = 0;
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
};
AbstractWrapper::~AbstractWrapper() {}

class IntegerWrapper : public AbstractWrapper {
	int *ptr;
public:
	IntegerWrapper(int *ptr)
		: AbstractWrapper("int"), ptr(ptr) {}
	virtual ~IntegerWrapper() {
		delete ptr;
	}
	virtual string type() { return "int"; }
	virtual string to_string() {
		return std::to_string(*ptr);
	}
};

class StringWrapper : public AbstractWrapper {
protected:
	char *ptr;
	int len;
public:
	StringWrapper(char *ptr, int len, string name = "string")
		: AbstractWrapper(name), ptr(ptr), len(len) {}
	virtual ~StringWrapper() { delete[] ptr; }
	int length() { return len; }
	virtual string type() { return "string"; }
	virtual string to_string() {
		return string(ptr, len);
	}
};

class ChineseStringWrapper : public StringWrapper {
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int len)
		: StringWrapper(ptr, len, "chineseString") {}
	virtual string type() { return "chineseString"; }
	using StringWrapper::length;
	int length(bool rawChars) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
};
