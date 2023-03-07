#pragma once
#include<string>

using namespace std;
struct Element {
	int atomicNum;
	double mass;
	string name;
	string nameAbbriv;
	Element* next;
};

Element** get_table(int& size);
void print_table(Element** table, int size);
