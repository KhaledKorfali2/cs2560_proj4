#include <iostream>
#include <fstream>
#include <string>
#include "Element.h"

using namespace std;

Element** get_table(int& size) {
    Element* head = nullptr;
    Element* tail = nullptr;
    string line;
    ifstream file("periodictable.dat");
    if (file.is_open()) {
        while (getline(file, line)) {
            Element* new_element = new Element;
            if (!new_element) {
                cerr << "Error: Memory allocation failed for new_element" << endl;
                while (head) {
                    Element* temp = head;
                    head = head->next;
                    delete temp;
                }
                return nullptr;
            }
            size_t pos = 0;
            string token;
            pos = line.find('\t');
            token = line.substr(0, pos);
            new_element->name = token;
            line.erase(0, pos + 1);
            pos = line.find('\t');
            token = line.substr(0, pos);
            new_element->nameAbbriv = token;
            line.erase(0, pos + 1);
            pos = line.find('\t');
            token = line.substr(0, pos);
            new_element->atomicNum = stoi(token);
            line.erase(0, pos + 1);
            new_element->mass = stod(line);
            new_element->next = nullptr;
            if (!head) {
                head = new_element;
                tail = new_element;
            }
            else {
                tail->next = new_element;
                tail = new_element;
            }
        }
        file.close();
    }
    else {
        cerr << "Error: Could not open file" << endl;
        return nullptr;
    }
    Element** table = new Element * [size];
    if (!table) {
        cerr << "Error: Memory allocation failed for table" << endl;
        while (head) {
            Element* temp = head;
            head = head->next;
            delete temp;
        }
        return nullptr;
    }
    int i = 0;
    while (head) {
        table[i] = head;
        head = head->next;
        i++;
    }
    size = i;
    return table;
}
