#include "DLL_First_Last.h"

void createList(List &L){
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElement(infotype data){
    address P;
    P = new elmList;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void insertLast(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertFirst(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        last(L) = P;
    } else{
        prev(first(L)) = P;
        next(P) = first(L);
        first(L) = P;
    }
}
void insertAfter(address Prec, address P){
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
    prev(P) = Prec;
}

void insertAscending(List &L, infotype dataBaru){
    address P;
    P = createNewElement(dataBaru);

    if (first(L) == NULL){
        insertFirst(L, P);
    } else{
        if (info(P)<=info(first(L))){
            insertFirst(L,P);
        } else if (info(P)>= info(last(L))){
            insertLast(L,P);
        } else {
            address Q;
            Q = first(L);
            while (next(Q)!= P){
                Q = next(Q);
            }
            insertAfter(Q,P);
        }
    }
}

address deleteFirst(List &L, address P){
    P = first(L);
    if (next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        first(L) = next(first(L));
        prev(first(L)) = NULL;
        next(P) = NULL;
    }
    return P;
}
address deleteLast(List &L, address P){
    P = last(L);
    if (next(first(L)) == NULL){
        first(L) = NULL;
        last(L) = NULL;
    } else {
        last(L) = prev(last(L));
        next(last(L)) = NULL;
        prev(P) = NULL;
    }
    return P;
}

address deleteAfter(address Prec, address P){
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    prev(P) = NULL;
    next(P) = NULL;
    return P;
}

void deleteElemen(List &L, infotype dataHapus){
    address P;
    address temp;
    P = createNewElement(dataHapus);
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else{
        if (info(P) == info(first(L))){
            temp = deleteFirst(L,P);
        } else if (info(P) == info(last(L))){
            temp = deleteLast(L,P);
        } else {
            address Q;
            Q = first(L);
            while (next(Q)!= P){
                Q = next(Q);
            }
            temp = deleteAfter(Q,P);
        }
    }
}

void printList(List L){
    address P;
    P = first(L);
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    } else{
        while (P!= NULL){
            cout << info(P) << " ";
            P = next(P);
        }
        cout << endl;
    }
}

bool findElement(List L, infotype dataDicari){
    address P;
    P = first(L);
    while (P != NULL && info(P)!= dataDicari){
        P = next(P);
    }
    return info(P) == dataDicari;
}

int frequencyOfElm(List L, infotype dataDicari){
    int freq;
    if (first(L) == NULL){
        freq = 0;
    } else{
        address P;
        freq = 0;
        P = first(L);
        while (P != NULL){
            if (info(P) == dataDicari){
                freq++;
            }
            P = next(P);
        }
    }
    return freq;
}
