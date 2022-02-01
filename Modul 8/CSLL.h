#ifndef CSLL_H_INCLUDED
#define CSLL_H_INCLUDED

#include <iostream>

#define info(P) P->info
#define next(P) P->next
#define first(L) L.first

using namespace std;

const int max_applications = 5;

struct aplikasi {
    string nama;
    int prioritas;
    int sisa_durasi;
};
typedef aplikasi infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address createNewElement(infotype data);

void insertFirst(List &L, address P);
void insertLast(List &L, address P);
void insertAfter(address Prec, address P);
void insertDescending(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address Prec, address &P);
void deleteElement(List &L, address P);

void printList(List L);

int panjangList(List L);
void insertAplikasi(List &L, infotype data);
int eksekusi(address P, int durasi);
void eksekusiMulti(List &L, address &current, int N, int duration);


#endif // CSLL_H_INCLUDED
