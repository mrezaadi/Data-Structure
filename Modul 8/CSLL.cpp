#include "CSLL.h"

void createList(List &L){
    first(L) = NULL;
}

address createNewElement(infotype data){
    address P;
    P = new elmList;
    info(P) = data;
    next(P) = NULL;
    return P;
}

void insertFirst(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        next(P) = first(L);
    } else{
        next(P) = first(L);
        address Q;
        Q = first(L);
        while (next(Q)!=first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P){
    if (first(L) == NULL){
        first(L) = P;
        next(P) = P;
    } else{
        next(P) = first(L);
        address Q;
        Q = first(L);
        while (next(Q)!=first(L)){
            Q = next(Q);
        }
        next(Q) = P;
    }
}

void insertAfter(address Prec, address P){
    next(P) = next(Prec);
    next(Prec) = P;
}

void deleteFirst(List &L, address &P){
    P = first(L);
    if (next(first(L)) == first(L)){
        next(P) = NULL;
        first(L) = NULL;
    } else{
        address Q;
        Q = first(L);
        while (next(Q) != first(L)){
            Q = next(Q);
        }
        next(Q) = next(P);
        first(L) = next(P);
        next(P) = NULL;
    }
}

void deleteLast(List &L, address &P){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
        cout << endl;
    } else if (next(first(L)) == first(L)){
        P = first(L);
        first(L) = NULL;
    } else{
        address Q;
        Q = first(L);
        while (next(next(Q)) != first(L)){
            Q = next(Q);
        }
        P = next(Q);
        next(Q) = next(P);
        next(P) = NULL;
    }
}

void deleteAfter(address Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = NULL;
}

void printList(List L){
    if (first(L) == NULL){
        cout << "List kosong" << endl;
        cout << endl;
    } else{
        address P;
        P = first(L);
        while (next(P) != first(L)){
            cout << info(P).nama << info(P) << info(P).sisa_durasi << endl;
            i++;
            P = next(P);
        }
        cout << info(P).nama << info(P) << info(P).sisa_durasi << endl;
        i++;
        cout << endl;
    }
}

int eksekusi(address P, int durasi){
    return info(P).sisa_durasi - durasi
}

int panjangList(List L){
    int panjang;
    if (first(L) == NULL){
        panjang = 0;
    } else {
        address P = first(L);
        while (P!=NULL){
            P = next(P);
            panjang++;
        }
    }
    return panjang;
}

void insertDescending(List &L, address P){
    if (first(L) == NULL){
        inserFirst(L,P);
    } else{
        address Q = first(L);
        address prec;
        while (info(P).prioritas < info(Q).prioritas){
            prec = Q;
            Q = next(Q);
        }
        if (Q == first(L)){
            insertFirst(L,P);
        } else if (next(Q) == first(L)){
            insertLast(L,P);
        } else{
            insertAfter(prec,P);
        }
    }
}

void insertAplikasi(List &L, infotype data){
    //Cari prioritas terendah, elemen terakhir
    address prioritas_min;
    prioritas_min = first(L);
    while (next(prioritas_min) != first(L)){
        prioritas_min = next(prioritas_min);
    }

    //Buat elemen aplikasi baru
    address P;
    P = createNewElement(data);

    //Cek Kondisi
    if (panjangList(L)< max_applications || info(P).prioritas > info(prioritas_min).prioritas){
        insertDescending(L,P);
    } else {
        address temp;
        deleteLast(L,temp);
        insertDescending(L,P);
        cout << info(temp).nama << endl;
        cout << info(temp).prioritas << endl;
        cout << info(temp).sisa_durasi << endl;
    }
}

void eksekusiMulti(List &L, address &current, int N, int duration){
    address temp;
    while (N>0 && next(current)!= first(L)){
        info(current).sisa_durasi = info(current).sisa_durasi - eksekusi(current, duration);
        if (info(current).sisa_durasi<=0){
            deleteElement(L, temp);
        }
        N--;
    }
}
