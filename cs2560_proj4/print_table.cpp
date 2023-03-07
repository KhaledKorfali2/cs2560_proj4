#include <iostream>
#include <iomanip>
#include "Element.h"

using namespace std;


void print_table(Element** table, int size) {
    cout << "Periodic Table by K. Korfali" << endl << endl;
    cout << "Name                    Abr ANo   M";
    cout << "----------------------- --- --- ------" << endl;

    cout << setprecision(2) << fixed << showpoint;
    for (int i = 0; i < size; i++) {
        cout << setw(23) <<table[i]->name << " " << setw(2) << " " << 
                setw(3) << table[i]->nameAbbriv << " " << setw(3) << 
                table[i]->atomicNum << " " << setw(6) << table[i]->mass << endl;
    }
    cout << endl;
    cout << "The average mass =\t\t"  << get_average_mass(table, size) << endl;
    cout << "The number of elements =\t\t" << size << endl;
}
