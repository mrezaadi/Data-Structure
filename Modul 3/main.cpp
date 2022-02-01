#include "catalog.h"

int main(){
    /*
        Nama    : Muhammad Reza Adi Nugraha
        NIM     : 1301204078
    */
    //Inisiasi variabel
    catalog storage;
    storage.maks = 8;
    storage.num = -1;

    //Menambahkan data & output
    add_data(storage, 6);
    view_data(storage);
    add_data(storage, 4);
    view_data(storage);
    add_data(storage, 8);
    view_data(storage);
    add_data(storage, 2);
    view_data(storage);

    cout << endl;

    //Mencari index
    int i;
    i = search_data(storage, 8);
    cout << i << endl;
    i = search_data(storage, 5);
    cout << i << endl;

    //Mandiri
    reversed_view(storage);
    add_data(storage, 5);
    reversed_view(storage);

    cout << endl;

    view_data(storage);
    delete_data(storage);
    view_data(storage);
}

