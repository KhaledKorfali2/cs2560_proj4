//
// Name:	Korfali, Khaled
// Project:	4
// Due: 	03-15-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code is responsible for defining an Element structure which
//		stores the element's atomic number, mass, name, and abbreviation.
//
//		It also ontains the function prototypes for the get_table function
//		and print_table functions.
//
//


#pragma once
#include <string>

// Element Structure
struct Element {
	int atomicNum;
	double mass;
	std::string name;
	std::string nameAbbriv;
};

// Function prototypes
Element** get_table(int& size);
void print_table(Element** table, int size);
