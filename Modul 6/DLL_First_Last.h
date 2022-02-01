#ifndef DLL_FIRST_LAST_H_INCLUDED
#define DLL_FIRST_LAST_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last

using namespace std;

typedef int infotype;
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
address createNewElement(infotype data);
void insertLast(List &L, address P);
void insertFirst(List &L, address P);
void insertAfter(address Prec, address P);
void insertAscending(List &L, infotype dataBaru);
address deleteFirst(List &L, address P);
address deleteLast(List &L, address P);
address deleteAfter(List &L, address Prec, address P);
void deleteElemen(List &L, infotype dataHapus);
void printList(List L);
bool findElement(List L, infotype dataDicari);
int frequencyOfElm(List L, infotype dataDicari);

#endif // DLL_FIRST_LAST_H_INCLUDED
