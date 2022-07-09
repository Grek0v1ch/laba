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