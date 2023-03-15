//
// Name:	Korfali, Khaled
// Project:	4
// Due: 	03-15-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This program reads data from a file containing information about chemical elements
//		and then prints the periodic table of elements sorted by name. It uses a struct to
//		store the element data, and a linked list to dynamically create the struct elements.
//		The periodic table is printed using an array of pointers to the element struct.
//		The program also deallocates the memory used to store the element data.
//


#include <iostream>
#include <algorithm>
#include "Element.h"


using namespace std;


//Function prototypes
void selectionSort(Element** array, int size);

int main() {
	// The number of elements in the periodic table
	int size = 0;

	// Call the get_table function to read the periodic table data and store it in an array of Element pointers
	Element** table = get_table(size);

	// Check if the table is null, indicating an error occurred while reading the file
	if (!table) {
		cerr << "Error: Could not read periodic table" << endl; // Output error to console
		return 1; // return 1 to indicate error
	}

	// Sort table in order of element name (a to z)
	//selectionSort(table, size);

	// Print the periodic table using the sorted array of Element pointers
	print_table(table, size);
  
	// Deallocate the memory used to store the element data
	for (int i = 0; i < size; i++) {
		delete table[i];
	}
	delete[] table;

	// Return 0 to indicate successfull execution (final endl is in print_table.cpp)
	return 0;
}

// Uses the selection sort algorithm to compare two strings and order them in alphabetical order
void selectionSort(Element** array, int size) {
	// loop through each element in the array except the last one
	for (int i = 0; i < size - 1; i++) {
		// set the minimum index to the current element
		int minIndex = i;
		// loop through the rest of the array to find the minimum element
		for (int j = i + 1; j < size; j++) {
			// if the name of the current element is less than the name of the minimum element,
			// update the minimum index to the current index
			if (array[j]->name < array[minIndex]->name) {
				minIndex = j;
			}
		}
		// if the minimum index is not the current index, swap the elements
		if (minIndex != i) {
			swap(array[i], array[minIndex]);
		}
	}
}
