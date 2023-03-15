//
// Name:	Korfali, Khaled
// Project:	4
// Due: 	03-15-2023
// Course:	cs-2560-01-sp23
//
// Description:
//		This code reads data from a file called "periodictable.dat" that contains
//		information about the periodic table of elements. It creates a linked list
//		of elements and then converts it into an array of pointers to Element objects
//


#include <iostream>
#include <fstream>
#include <string>
#include "Element.h"

using namespace std;

// Node datatype that's used to create a linked list
struct Node {
	Element* element; // Pointer to an Element object
	Node* next; // Pointer to the next node in the linked list
};

// This function reads data from a file and returns an array of pointers to Element objects
Element** get_table(int& size) {
	Node* head = nullptr; // Pointer to the head of the linked list
	Node* tail = nullptr;// Pointer to the tail of the linked list
	string line; // Used to store each line in periodictable.dat file
	size = 0;// The number of elements in the linked list

	// Open the file "periodictable.dat"
	ifstream inFile("periodictable.dat");

	// Check if the file was successfully opened
	if (inFile.is_open()) {
		// Read each line in the file
		while (getline(inFile, line)) {
			// Create a new Element object
			Element* element = new Element;

			// Read the atomic number, abbreviation, mass, and name of the element from the file
			inFile >> element->atomicNum >> element->nameAbbriv >> element->mass >> element->name;

			// Check if there was an error reading from the file
			if (!inFile.good()) {
				delete element; // Delete the Element object if there was an error
				break;
			}
			// Increment the size of the linked list
			size++;

			// Create a new node and add it to the end of the linked list
			Node* node = new Node{ element, nullptr };
			if (head == nullptr) {
				head = node;
				tail = node;
			}
			else {
				tail->next = node;
				tail = node;
			}
		}
	}
	// Display an error message if the file can't be opened
	else 
	{
		cerr << "Error Can't open file" << endl;
	}
	// Close the file
	inFile.close();

	// Create an array of pointers to Element objects
	Node* node = head;

	// Convert the linked list to an array
	Element** elements = new Element * [size];
	for (int i = 0; i < size; i++) {
		elements[i] = node->element;// Add the current element to the array
		Node* temp = node;// Move to the next node in the linked list
		node = node->next;
		delete temp;// Delete the current node
	}

	// Return the array of Element pointers
	return elements;
}
