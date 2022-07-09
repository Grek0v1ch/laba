#include "Pyramid.h"
#include <iostream>

Pyramid::Pyramid(double angle_c, double side_a, double side_b, double height) :
	Acute_triangle(angle_c, side_a, side_b),
	_height(height) {
	if (_height < 0) throw std::string("invalid_parameters");
}

Pyramid& Pyramid::operator=(const Pyramid& object) {
	if (&object == this) return *this;
	_angle_c = object._angle_c;
	_side_a = object._side_a;
	_side_b = object._side_b;
	_height = object._height;
	return *this;
}

double Pyramid::get_volume() const {
	return _height * get_area();
}

double Pyramid::get_surface_area() {
	double radius = get_area() / (0.5 * get_perimetr());
	double apothema = sqrt(radius * radius + _height * _height);
	return apothema * get_perimetr() * 0.5;
}

void Pyramid::print() {
	std::cout << "Information about a pyramid:" <<
				 "\n  Volume = " << get_volume() <<
				 "\n  Surface area = " << get_surface_area() << '\n';
}