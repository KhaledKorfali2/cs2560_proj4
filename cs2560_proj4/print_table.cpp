//
// Name:	Korfali, Khaled
// Project:	4
// Due: 	03-15-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code prints the periodic table of elements using an array
//		of Element pointers
//
#include <iostream>
#include <iomanip>
#include "Element.h"

using namespace std;

// This function takes an array of Element pointers and the size of the array and prints the periodic table
void print_table(Element** table, int size) {
	double totalMass = 0;// The total mass of all the elements in the table

	// Display header text
	cout << "Periodic Table by K. Korfali" << endl << endl;
	cout << "Name                    Abr ANo   Mass" << endl;
	cout << "----------------------- --- --- ------" << endl;

	// Format floating point numbers
	cout << setprecision(2) << fixed << showpoint;

	// Print each element in the table
	for (int i = 0; i < size; i++) {
		// Print the name, abbreviation, atomic number, and mass of the element
		cout << left << setw(23) << table[i]->name       << " ";
		cout << left << setw(3)  << table[i]->nameAbbriv << " ";
		cout << right << setw(3)  << table[i]->atomicNum  << " ";
		cout << right << setw(6)  << table[i]->mass       << endl;

		// Add the mass of the current element to the total mass
		totalMass += table[i]->mass;
	}

	// Print the average mass and number of elements in the table
	cout << endl;
	cout << "The average mass =              "  << right << setw(6) << totalMass/size << endl;
	cout << "The number of elements =    " << right << setw(3) << size << endl;
}
