#include <iostream>
#include <fstream>
#include <string>
#include "Element.h"

using namespace std;

struct Node {
    Element* element;
    Node* next;
};

Element** get_table(int& size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    string line;
    size = 0;

    ifstream inFile("periodictable.dat");
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            Element* element = new Element;
            inFile >> element->atomicNum >> element->nameAbbriv >> element->mass >> element->name;
            if (!inFile.good()) {
                delete element;
                break;
            }
            size++;
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
    else 
    {
        cerr << "Error Can't open file" << endl;
    }
    inFile.close();

    
    Node* node = head;
  /*  while (node != nullptr) {
        numElements++;
        node = node->next;
    }*/

    Element** elements = new Element * [size];
    //node = head;
    for (int i = 0; i < size; i++) {
        elements[i] = node->element;
        Node* temp = node;
        node = node->next;
        delete temp;
    }

    return elements;
}
