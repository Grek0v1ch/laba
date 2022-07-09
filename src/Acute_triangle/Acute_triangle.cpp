#include "Acute_triangle.h"
#include <iostream>
#include <string>

Acute_triangle::Acute_triangle(double angle_c, double side_a, double side_b) {
	if (angle_c < 0 || side_a < 0 || side_b < 0) throw std::string("invalid_parameters");
	_angle_c = angle_c;
	_side_a = side_a;
	_side_b = side_b;
	if (get_angle_a() >= 90 || get_angle_b() >= 90 || get_angle_c() >= 90)
		throw std::string("not_acute_triangle");
}

Acute_triangle& Acute_triangle::operator=(const Acute_triangle& object) {
		if (&object == this) return *this;
		_angle_c = object._angle_c;
		_side_a = object._side_a;
		_side_b = object._side_b;
		return *this;
	}

double Acute_triangle::get_side_a() const {
	return _side_a;
}

double Acute_triangle::get_side_b() const {
	return _side_b;
}

double Acute_triangle::get_side_c() const {
	return sqrt(_side_a * _side_a + _side_b * _side_b -
				2 * _side_a * _side_b * cos(to_rad(_angle_c)));
}

double Acute_triangle::get_angle_a() const {
	return to_grad(asin(_side_a * sin(to_rad(_angle_c)) / get_side_c()));
}

double Acute_triangle::get_angle_b() const {
	return to_grad(asin(_side_b * sin(to_rad(_angle_c)) / get_side_c()));
}

double Acute_triangle::get_angle_c() const {
	return _angle_c;
}

double Acute_triangle::get_perimetr() const {
	return _side_a + _side_b + get_side_c();

}

double Acute_triangle::get_area() const {
	return 0.5 * _side_b * _side_a * sin(to_rad(_angle_c));
}

void Acute_triangle::print() {
	std::cout << "Information about an acute-angled triangle:" <<
				 "\n  Side a = " << get_side_a() <<
				 "\n  Side b = " << get_side_b() <<
				 "\n  Side c = " << get_side_c() <<
				 "\n  Angle A = " << get_angle_a() <<
				 "\n  Angle B = " << get_angle_b() <<
				 "\n  Angle C = " << get_angle_c() <<
				 "\n  Perimeter = " << get_perimetr() <<
				 "\n  Area = " << get_area() << '\n';
}