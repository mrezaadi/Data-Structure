#include "mylist.h"

void createList(List &L){
    first(L) = nil;
}
infotype newMahasiswa(string nama, string nim, double ipk){
    infotype mhs;
    mhs.nama = nama;
    mhs.nim = nim;
    mhs.ipk = ipk;
    return mhs;
}
address newElement(infotype dataBaru){
    address P;
    P = new elmList;
    info(P) = dataBaru;
    next(P) = nil;
    return P;
}
void insertFirst(List &L, address P){
    if(first(L) == nil){
        first(L) = P;
    } else{
        next(P) = first(L);
        first(L) = P;
    }
}
void insertLast(List &L, address P){
    if (first(L) == nil){
        first(L) = P;
    } else{
        address Q = first(L);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
address deleteFirst(List &L, address P){
    P = first(L);
    if(next(first(L)) == nil){
        first(L) = nil;
    } else{
        first(L) = next(first(L));
    }
    next(P) = nil;
    return P;
}
address deleteLast(List &L, address P){
    if(next(first(L)) == nil){
        first(L) = nil;
    } else{
        P = first(L);
        address Q = first(L);
        while (next(P) != nil){
            Q = P;
            P = next(P);
        }
        next(Q)=nil;
    }
    return P;
}
void printList(List L){
    if (first(L) == nil){
        cout << "List Kosong !" << endl;
    } else{
        int i = 1;
        address P = first(L);
        while (P != nil){
            cout << "[" << i << "]"<<endl;
            cout << "Nama \t: " << info(P).nama <<endl;
            cout << "NIM \t: " << info(P).nim <<endl;
            cout << "IPK \t: " << info(P).ipk <<endl;
            P = next(P);
            i++;
        }
        cout << "List selesai ditampilkan!" << endl;
        cout << endl;
    }
}
