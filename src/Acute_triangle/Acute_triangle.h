#ifndef ACUTE_TRIANGLE_CPP
#define ACUTE_TRIANGLE_CPP

#define to_rad(x) (x * M_PI / 180.0)
#define to_grad(x) (x * 180.0 / M_PI)

#include "../Figure/Figure.h"
#include <cmath>

class Acute_triangle : public Figure {
protected:
	double _angle_c, _side_a, _side_b;
public:
	Acute_triangle() : _angle_c(0), _side_a(0), _side_b(0) {}
	Acute_triangle(double angle_c, double side_a, double side_b);
	Acute_triangle(const Acute_triangle& object) :
		_angle_c(object._angle_c), _side_a(object._side_a), _side_b(object._side_b) {}
	~Acute_triangle() {}

	Acute_triangle& operator=(const Acute_triangle& object);

	double get_side_a() const;
	double get_side_b() const;
	double get_side_c() const;

	double get_angle_a() const;
	double get_angle_b() const;
	double get_angle_c() const;

	double get_perimetr() const;
	double get_area() const;

	void print() override;
};

#endif // ACUTE_TRIANGLE_CPP
