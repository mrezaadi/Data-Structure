#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define head(Q) Q.head
#define tail(Q) Q.tail

using namespace std;

typedef string infotype;
typedef struct elmQueue *address;

struct elmQueue{
    infotype info;
    address next;
};

struct Queue {
    address head;
    address tail;
};

address createElmt(infotype data);
void masukkan_transaksi(Queue &Q, address P);
void transaksi(Queue &Q, address &P);
void printQueue(Queue Q);

#endif // QUEUE_H_INCLUDED
