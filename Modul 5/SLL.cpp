#include "SLL.h"

void create_list(List &L){
    first(L) = nil;
}

void insert_last(List &L, address P) {
    if (first(L)==nil){
        first(L)=P;
    } else {
        address addressBerjalan = first(L);
        while (next(addressBerjalan) != nil) {
            addressBerjalan = next(addressBerjalan);
        }
        next(addressBerjalan) = P;
    }
}

void delete_first(List &L, address &P) {
    P = first(L);
    if (next(first(L)) == nil) {
        first(L) = nil;
    } else {
        first(L) = next(first(L));
    }
    next(P) = nil;
}

void delete_after(List &L, address Prec, address &P){
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = nil;
}

void delete_last(List &L, address &P){
    address q = first(L);
    while (next(next(q)) != nil){
        q = next(q);
    }
    P=next(q);
    next(q)= nil;
}

    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
void new_element(infotype peg, address &P){
    P = new elmtPeg;
    info(P) = peg;
    next(P) = nil;
}

    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
void add_N_data(List &ListPeg){
    int N;
    infotype data;
    address P;
    string nama, nip;
    int gaji;

    cout << "Masukkan N: ";
    cin >> N;

    for (int i=1; i <= N; i++){
        cout << "NAMA \t: ";
        cin >> nama;
        cout << "NIP \t: ";
        cin >> nip;
        cout << "GAJI \t: ";
        cin >> gaji;

        data.nama = nama;
        data.nip = nip;
        data.gaji = gaji;

        cout << endl;
        new_element(data, P);
        insert_last(ListPeg, P);
    }
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
void show_all_data(List ListPeg){
    address P;
    int i = 1;

    P = first(ListPeg);
    while (P != nil){
        cout << "[" << i << "]" << endl;
        cout << "Nama \t: " << info(P).nama << endl;
        cout << "NIP \t: " << info(P).nip << endl;
        cout << "Gaji \t: Rp. " << info(P).gaji << endl;
        P = next(P);
        i++;
        cout << endl;
    }
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
address search_by_nip(List ListPeg, string NIP){
    address P;
    P = first(ListPeg);
    while (P != nil && info(P).nip != NIP){
        P = next(P);
    }
    return P;
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
void delete_Data(List &ListPeg, string NIP){
    address data;
    address temp;
    data = search_by_nip(ListPeg, NIP);

    if (first(ListPeg) == nil){
        cout << "List Kosong" << endl;
    } else if (data == first(ListPeg)){
        delete_first(ListPeg, temp);
    } else if(next(data) == nil){
        delete_last(ListPeg, temp);
    } else {
        address P;
        P = first(ListPeg);
        while (next(P) != data){
            P = next(P);
        }
        delete_after(ListPeg, P, temp);
    }
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
int jumlah_pegawai(List ListPeg){
    int jumlah = 0;
    address P;

    P = first(ListPeg);
    while (P != nil){
        jumlah++;
        P = next(P);
    }
    return jumlah;
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
int total_salary(List ListPeg){
    int total = 0;
    address P;

    P = first(ListPeg);
    while (P != nil){
        total = total + info(P).gaji;
        P = next(P);
    }
    return total;
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
string max_gaji(List ListPeg){
    address maks = first(ListPeg);
    address P = next(first(ListPeg));

    while (P != nil){
        if (info(P).gaji >= info(maks).gaji){
            info(maks).gaji = info(P).gaji;
        }
        P = next(P);
    }
    return info(maks).nama;
}
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
int menu(){
    cout << "========== MENU ==========" << endl;
    cout << "1. Tambah data pegawai" << endl;
    cout << "2. Tampilkan data pegawai" << endl;
    cout << "3. Cari data pegawai berdasarkan NIP" << endl;
    cout << "4. Hapus data berdasarkan NIP" << endl;
    cout << "5. Jumlah pegawai saat ini" << endl;
    cout << "6. Rata-rata penghasilan pegawai" << endl;
    cout << "7. Nama pegawai dengan gaji tertinggi" << endl;
    cout << "0. Exit" << endl;

    cout << "Pilihan menu: ";

    int input;
    cin >> input;
    return input;
}
