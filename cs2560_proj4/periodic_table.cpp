#include <iostream>
#include <algorithm>
#include "Element.h"

using namespace std;

int main() {
    int size = 118;
    Element** table = get_table(size);
    if (!table) {
        cerr << "Error: Could not read periodic table" << endl;
        return 1;
    }
    sort(table, table + size, [](const Element* a, const Element* b) {return a->name < b->name; });
    print_table(table, size);
    double total_mass = 0.0;
    for (int i = 0; i < size; i++) {
        total_mass += table[i]->mass;
    }
    double avg_mass = total_mass / size;
    cout << "The average mass = " << avg_mass << endl;
    cout << "The number of elements = " << size << endl;
    for (int i = 0; i < size; i++) {
        delete table[i];
    }
    delete[] table;
    return 0;
}
