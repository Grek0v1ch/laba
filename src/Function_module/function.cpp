#include "function.h"

void read_figures(std::ifstream& finput, List<Figure*>& list) {
	int count;
	finput >> count;
	for (int i = 0; i < count; i++) {
		int number;
		double angle_c, side_a, side_b, height;
		finput >> number;
		if (number == 0) {
			finput >> angle_c >> side_a >> side_b;
			try {
				list.push_back(new Acute_triangle(angle_c, side_a, side_b));
			} catch (std::string ex) {
				if (ex == "invalid_parameters")
					std::cout << "In line " << i + 1 << " figure invalid arguments\n";
				else if (ex == "not_acute_triangle")
					std::cout << "In line " << i + 1 << " not acute triangle\n";
			}
		} else if (number == 1) {
			finput >> angle_c >> side_a >> side_b >> height;
			try {
				list.push_back(new Pyramid(angle_c, side_a, side_b, height));
			} catch (std::string ex) {
				if (ex == "invalid_parameters")
					std::cout << "In line " << i + 1 << " figure invalid arguments\n";
				else if (ex == "not_acute_triangle")
					std::cout << "In line " << i + 1 << " not acute triangle at the base\n";
			}
		}
	}
}

void print_figures(List<Figure*>& list) {
	pnode<Figure*> curr = list.front();
	int count = 1;
	while (curr) {
		std::cout << "Figure " << count << '\n';
		curr->value()->print();
		std::cout << '\n';
		curr = curr->next();
		count++;
	}
}

void find_triangle_and_pyramid(List<Figure*>& list, Acute_triangle& triangle, Pyramid& pyramid) {
	pnode<Figure*> curr = list.front();
	while (curr) {
		auto& value = *(curr->value());
		if (typeid(value) == typeid(triangle)) {
			Acute_triangle* object = dynamic_cast<Acute_triangle*>(curr->value());
			if (std::max(triangle.get_side_a(),
						 std::max(triangle.get_side_b(), triangle.get_side_c()))
				< std::max(object->get_side_a(),
						   std::max(object->get_side_b(), object->get_side_c())))
			triangle = *object;
		} else if (typeid(value) == typeid(pyramid)) {
			Pyramid* object = dynamic_cast<Pyramid*>(curr->value());
			if (pyramid.get_volume() < object->get_volume())
				pyramid = *object;
		}
		curr = curr->next();
	}
}