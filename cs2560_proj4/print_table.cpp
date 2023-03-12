#include <iostream>
#include <iomanip>
#include "Element.h"

using namespace std;


void print_table(Element** table, int size) {
    double totalMass = 0;
    cout << "Periodic Table by K. Korfali" << endl << endl;
    cout << "Name                    Abr ANo   Mass" << endl;
    cout << "----------------------- --- --- ------" << endl;

    cout << setprecision(2) << fixed << showpoint;
    for (int i = 0; i < size; i++) {
        cout << left << setw(23) << table[i]->name       << " ";
        cout << left << setw(3)  << table[i]->nameAbbriv << " ";
        cout << right << setw(3)  << table[i]->atomicNum  << " ";
        cout << right << setw(6)  << table[i]->mass       << endl;

        totalMass += table[i]->mass;
    }
    cout << endl;
    cout << "The average mass =              "  << right << setw(6) << totalMass/size << endl;
    cout << "The number of elements =    " << right << setw(3) << size << endl;
}
