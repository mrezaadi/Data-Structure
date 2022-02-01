#ifndef CATALOG_H_INCLUDED
#define CATALOG_H_INCLUDED

/*
    Nama    : Muhammad Reza Adi Nugraha
    NIM     : 1301204078
*/

#include <iostream>
using namespace std;

const int nMax = 50;

struct catalog {
    int data[nMax];
    int maks;
    int num;
};

void add_data(catalog &C, int x);
void view_data(catalog C);
int search_data(catalog C, int x);
void reversed_view(catalog C);
void delete_data(catalog &C);

#endif // CATALOG_H_INCLUDED
