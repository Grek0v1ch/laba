#include <iostream>
#include <fstream>
#include "Acute_triangle/Acute_triangle.h"
#include "Pyramid/Pyramid.h"
#include "DLList/dllist.h"
#include "Function_module/function.h"

int main() {
	List<Figure*> list;
	std::ifstream finput("../src/input.txt");

	read_figures(finput, list);
	print_figures(list);
	Acute_triangle triangle;
	Pyramid pyramid;
	find_triangle_and_pyramid(list, triangle, pyramid);
	triangle.print();
	pyramid.print();

	finput.close();
	return 0;
}