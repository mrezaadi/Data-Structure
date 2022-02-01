#include "CSLL.h"

int main(){
    List L;
    address P,Q,temp;
    infotype data;

    createList(L);

    data.nama = "word";
    data.prioritas = 5;
    data.sisa_durasi = 10;
    insertAplikasi(L, data);

    data.nama = "excel";
    data.prioritas = 4;
    data.sisa_durasi = 20;
    insertAplikasi(L,data);

    data.nama = "chrome";
    data.prioritas = 8;
    data.sisa_durasi = 5;
    insertAplikasi(L,data);

    data.nama = "wa";
    data.prioritas = 7;
    data.sisa_durasi = 10;
    insertAplikasi(L,data);

    data.nama = "dota";
    data.prioritas = 10;
    data.sisa_durasi = 30;
    insertAplikasi(L,data);

    printList(L);

    data.nama = "power point";
    data.prioritas = 6;
    data.sisa_durasi = 15;

    printList(L);

    eksekusiMulti(L, first(L), 3, 10);

    printList(L);

    eksekusiMulti(L, next(first(L)), 3, 10);

    printList(L);
}
