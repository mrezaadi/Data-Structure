#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

using namespace std;

typedef char infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void createList(List &L);
void alokasi(infotype data, address &P);
void show(List L);

void insertFirst(List &L, address P);
void deleteFirst(List &L, address P);

int countX(List L, infotype data);

#endif // DLL_H_INCLUDED
