#ifndef PYRAMID_H
#define PYRAMID_H

#include "../Acute_triangle/Acute_triangle.h"

class Pyramid : private Acute_triangle {
private:
	double _height;
public:
	Pyramid() : Acute_triangle(), _height(0) {}
	Pyramid(double angle_c, double side_a, double side_b, double height);
	Pyramid(const Pyramid& object) : Acute_triangle(object), _height(object._height) {}
	~Pyramid() {}

	Pyramid& operator=(const Pyramid& object);

	double get_volume() const;
	double get_surface_area();

	void print() override;
};

#endif // PYRAMID_H
