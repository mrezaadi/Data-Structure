#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <iostream>
#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
using namespace std;

struct mahasiswa{
    string nama, nim;
    double ipk;
};

typedef mahasiswa infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
infotype newMahasiswa(string nama, string nim, double ipk);
address newElement(infotype dataBaru);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
address deleteFirst(List &L, address P);
address deleteLast(List &L, address P);
void printList(List L);

#endif // MYLIST_H_INCLUDED
