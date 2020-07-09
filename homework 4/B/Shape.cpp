#include "Shape.h"

Rectangle::Rectangle(const double &w, const double &h) : width(w), height(h) {}
double Rectangle::getArea() {
	return width * height;
}

const double Circle::Pi = 3.14;
Circle::Circle(const double &r) : radius(r) {}
double Circle::getArea() {
	return Pi * radius * radius;
}
