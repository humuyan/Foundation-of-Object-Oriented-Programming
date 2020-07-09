#pragma once

class Shape {
	public:
		virtual double getArea() = 0;
};
class Rectangle: public Shape {
	private:
		double width, height;

	public:
		Rectangle(const double &w, const double &h);
		double getArea() override;
};
class Circle: public Shape {
	private:
		const static double Pi;
		double radius;

	public:
		Circle(const double &r);
		double getArea() override;
};
