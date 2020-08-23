#pragma once
#include <list>
#include <iostream>
#include <memory>

#include "CustomClass.h"

class Content
{
	public:
		virtual ~Content() {}
};

class IntContent: public Content
{
private:
	int x;
public:
	IntContent(int _x): x(_x) {}
	friend std::ostream& operator<<(std::ostream& out, const IntContent& x) {
		out << x.x;
		return out;
	}
	void add(const int &y) {
		x += y;
	}
};

class StringContent: public Content
{
private:
	std::string x;
public:
	StringContent(std::string _x): x(_x) {}
	friend std::ostream& operator<<(std::ostream& out, const StringContent& x) {
		out << x.x;
		return out;
	}
	void add(const std::string &y) {
		x += y;
	}
};

class Object;
class VectorContent: public Content
{
private:
	std::vector<Object> x; //Object is not defined???
public:
	VectorContent(const std::vector<Object>& _x): x(_x) {}
	Object& visit(const int &pos) {
		return x[pos];
	}
};

class CustomContent: public Content
{
private:
	CustomClass x;
public:
	CustomContent(const CustomClass& _x): x(_x) {}
};

class Object
{
private:
	std::shared_ptr<Content> pt;

public:
	Object() {
		pt = nullptr;
	}
	Object(int x) {
		pt = std::make_shared<IntContent>(x);
	}
	Object(const std::string &x){
		pt = std::make_shared<StringContent>(x);
	}
	Object(const std::vector<Object> &x){
		pt = std::make_shared<VectorContent>(x);
	}
	Object(const CustomClass &x){
		pt = std::make_shared<CustomContent>(x);
	}

	friend std::ostream& operator<<(std::ostream& out, const Object& obj) {
		std::shared_ptr<IntContent> Int = std::dynamic_pointer_cast<IntContent>(obj.pt);
		std::shared_ptr<StringContent> String = std::dynamic_pointer_cast<StringContent>(obj.pt);
		if (Int) {
			out << *Int;
		} else {
			out << *String;
		}
		return out;
	}

	Object& operator+=(int y){
		std::dynamic_pointer_cast<IntContent>(pt)->add(y);
		return *this;
	}
	Object& operator+=(const std::string &y){
		std::dynamic_pointer_cast<StringContent>(pt)->add(y);
		return *this;
	}
	Object& operator[](const int &pos) {
		return std::dynamic_pointer_cast<VectorContent>(pt)->visit(pos);
	}
};
