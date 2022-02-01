#include "catalog.h"

void add_data(catalog &C, int x){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */

    //Kamus
    int i;
    int kondisi;

    //Algoritma
    i = 0;
    kondisi = -1;
    while (i < C.maks){
        if (kondisi == C.num){
            C.data[i] = x;
            C.num++;
            break;
        } else{
            kondisi++;
            i++;
        }
    }
}

void view_data(catalog C){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */

    //Kamus
    int i;

    //Algoritma
    for (i=0; i<=C.num; i++){
        cout << C.data[i] << " ";
    }
    cout << endl;
}

int search_data(catalog C, int x){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */

    //Kamus
    bool kondisi;
    int i, index;

    //Algoritma
    kondisi = false;
    index = -1;
    while (i < C.num && kondisi == false){
        if (C.data[i] == x){
            index = i;
            kondisi = true;
        } else{
            i++;
        }
    }
    return index;
}

void reversed_view(catalog C){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */

    //Kamus
    int i;

    //Algoritma
    for (i=C.num; i >=0; i--){
        cout << C.data[i] << " ";
    }
    cout << endl;
}

void delete_data(catalog &C){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */

    //Algoritma
    C.num--;
}
