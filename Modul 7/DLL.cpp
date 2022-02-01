#include "DLL.h"
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
void createList(List &L){
    first(L) = NULL;
    last(L) = NULL;
}
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
void alokasi(infotype data, address &P){
    P = new elmList;
    info(P) = data;
    next(P) = NULL;
    prev(P) = NULL;
}
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
void show(List L){
    address P;
    P = first(L);
    while (P != NULL){
        cout << info(P) << endl;
        P = next(P);
    }
    cout << endl;
}
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
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
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
void deleteFirst(List &L, address P){
    P = first(L);
    if (first(L) == NULL && last(L) == NULL){
        cout << "List kosong" << endl;
        cout << endl;
    } else if (first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    } else{
        first(L) = next(P);
        prev(first(L)) = NULL;
        next(P) = NULL;

    }
}
/*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
int countX(List L, infotype X){
    address P;
    int jumlah = 0;
    P = first(L);
    while (P != NULL){
        if (info(P) == X){
            jumlah++;
        }
        P = next(P);
    }
    return jumlah;
}
