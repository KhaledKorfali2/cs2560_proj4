#pragma once

using namespace std;
struct Element {
	int atomicNum;
	double mass;
	std::string name;
	std::string nameAbbriv;
};

Element** get_table(int& size);
void print_table(Element** table, int size);
