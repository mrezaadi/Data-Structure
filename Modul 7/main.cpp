#include "DLL.h"

int main(){
    List L;
    infotype data, X;
    address P;
    int N = 1;

    createList(L);
    /*  NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
    //Misalkan tanggal 5
    while (N <= 5){
        cout << "Masukkan karakter: ";
        cin >> data;
        alokasi(data, P);
        insertFirst(L,P);
        N++;
    }

    cout << "<<<<<<<<< PRINT LIST >>>>>>>>>" << endl;
    show(L);

    cout << "<<<<<<<<< COUNT X >>>>>>>>>" << endl;
    cout << "Masukkan karakter yang ingin dicari: ";
    cin >> X;
    cout << "Jumlah " << X << " dalam list: " << countX(L,X) << endl;

    cout << "<<<<<<<<< DELETE >>>>>>>>>" << endl;
    while (first(L) != NULL){
        deleteFirst(L, P);
    }
    show(L);


}
