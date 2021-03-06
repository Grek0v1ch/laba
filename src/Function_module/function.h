#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include "../Figure/Figure.h"
#include "../Acute_triangle/Acute_triangle.h"
#include "../Pyramid/Pyramid.h"
#include "../DLList/dllist.h"

void read_figures(std::ifstream& finput, List<Figure*>& list);
void print_figures(List<Figure*>& list);
void find_triangle_and_pyramid(List<Figure*>& list, Acute_triangle& triangle, Pyramid& pyramid);

#endif // FUNCTION_H
