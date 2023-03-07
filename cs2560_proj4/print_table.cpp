#include <iostream>
#include <iomanip>
#include "Element.h"

using namespace std;


void print_table(Element** table, int size) {
    double totalMass = 0;
    cout << "Periodic Table by K. Korfali" << endl << endl;
    cout << "Name                    Abr ANo   M";
    cout << "----------------------- --- --- ------" << endl;

    cout << setprecision(2) << fixed << showpoint;
    for (int i = 0; i < size; i++) {
        cout << setw(23) << table[i]->name       << " " << left;
        cout << setw(3)  << table[i]->nameAbbriv << " " << right;
        cout << setw(3)  << table[i]->atomicNum  << " " << left;
        cout << setw(6)  << table[i]->mass       << right << endl;

        totalMass += table[i]->mass;
    }
    cout << endl;
    cout << "The average mass =\t\t"  << totalMass/size << endl;
    cout << "The number of elements =\t\t" << size << endl;
}
