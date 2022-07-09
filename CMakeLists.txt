cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(laba1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "-g")

add_executable(laba1 src/main.cpp
					 src/Figure/Figure.h
					 src/Acute_triangle/Acute_triangle.h
					 src/Acute_triangle/Acute_triangle.cpp
					 src/Pyramid/Pyramid.h
					 src/Pyramid/Pyramid.cpp
					 src/DLList/dllist.h)