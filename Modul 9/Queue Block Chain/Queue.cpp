#include "Queue.h"
address createElmt(infotype data){
    address P;
    P = new elmQueue;
    info(P) = data;
    next(P) = NULL;
    return P;
}

void masukkan_transaksi(Queue &Q, address P){
    if (head(Q) == NULL){
        head(Q) = P;
    } else {
        next(tail(Q)) = P;
    }
}

void transaksi(Queue &Q, address &P){
    if (head(Q) == NULL){
        cout << "Queue Kosong" << endl;
    } else if (next(head(Q)) == NULL){
        P = head(Q);
        head(Q) = NULL;
    } else {
        P = head(Q);
        head(Q) = next(head(Q));
        next(P) = NULL;
    }
}

void printQueue(Queue Q){
    address P;
    P = head(Q);
    while (P != NULL){
        cout << info(P) << endl;
        P = next(P);
    }
}

