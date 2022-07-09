#ifndef ACUTE_TRIANGLE_CPP
#define ACUTE_TRIANGLE_CPP

#include "../Figure/Figure.h"

class Acute_triangle : public Figure {
private:
	double _angle_c, _side_a, _side_b;
public:
	Acute_triangle() : _angle_c(0), _side_a(0), _side_b(0) {}

	void print() override;
};

#endif // ACUTE_TRIANGLE_CPP
