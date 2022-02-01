#include "mylist.h"

int main(){
    /*
    List L;
    infotype Mhs;
    address P, temp;

    createList(L);
    printList(L);

    Mhs = newMahasiswa("Alice", "1301190202", 3.5);
    P = newElement(Mhs);
    insertFirst(L, P);

    Mhs = newMahasiswa ("Bob", "1301190203", 4);
    P = newElement(Mhs);
    insertFirst(L, P);

    printList(L);

    Mhs = newMahasiswa ("Chihaya", "1301190204", 3.6);
    P = newElement(Mhs);
    insertLast(L, P);

    Mhs = newMahasiswa("Delta", "1301190205", 2.7);
    P = newElement(Mhs);
    insertLast(L, P);

    Mhs = newMahasiswa("Euniche", "1301190201", 3.9);
    P = newElement(Mhs);
    insertFirst(L, P);

    printList(L);

    deleteFirst(L, temp);
    deleteLast(L, temp);
    printList(L);
`   */

    //MANDIRI
    /*
        NAMA        : MUHAMMAD REZA ADI NUGRAHA
        NIM         : 1301204078
        KODE ASPRAK : JES
    */


    //Kamus
    List L;
    infotype Mhs;
    address P, temp;
    string nama, nim;
    double ipk;

    //Algoritma
    createList(L); //Jangan lupa
    //SOAL 1
    cout<<"Masukkan Nama : ";
    cin>>nama;
    cout<<"Masukkan NIM  : ";
    cin>>nim;
    cout<<"Masukkan IPK  : ";
    cin>>ipk;

    while(nim != "-" && nama != "-"){
        cout<<endl;
        Mhs = newMahasiswa (nama, nim, ipk);
        P = newElement(Mhs);
        insertFirst(L, P);

        cout<<"Masukkan Nama : ";
        cin>>nama;
        cout<<"Masukkan NIM  : ";
        cin>>nim;
        cout<<"Masukkan IPK  : ";
        cin>>ipk;
    }
    //SOAL 2
    printList(L);
    while (first(L) != NULL){
        temp = deleteFirst(L, temp);
        cout << "<<<<<<<<<< DATA YANG DIHAPUS >>>>>>>>>" << endl;
        cout << "Nama : " <<info(temp).nama << endl;
        cout << "NIM : " <<info(temp).nim << endl;
        cout << "IPK : " <<info(temp).ipk << endl;
    }
    printList(L);
    return 0;
}
