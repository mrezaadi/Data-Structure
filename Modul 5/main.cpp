#include "SLL.h"

int main(){
    List L;
    address P;
    string nip;

    create_list(L);
    /*
    cout << "<<<<<<<<< INPUT DATA >>>>>>>>>" << endl;
    add_N_data(L);
    cout << endl;
    cout << "<<<<<<<<< DATA AWAL >>>>>>>>>" << endl;
    show_all_data(L);
    cout << endl;

    cout << "<<<<<<<<< HAPUS DATA >>>>>>>>>" << endl;
    cout << "Masukkan NIP yang ingin dihapus: ";
    cin >> nip;
    P = search_by_nip(L, nip);
    cout << "Data NIP yang ingin dihapus:" << endl;
    cout << "Nama \t: " << info(P).nama << endl;
    cout << "NIP \t: " << info(P).nip << endl;
    cout << "Gaji \t: " << info(P).gaji << endl;
    cout << endl;

    cout << "<<<<<<<<< SETELAH DATA DIHAPUS >>>>>>>>>" << endl;
    delete_Data(L, nip);
    show_all_data(L);

    cout << "Jumlah pegawai \t: " << jumlah_pegawai(L) << " pegawai"<< endl;
    cout << "Total Gaji \t: Rp. " << total_salary(L)<< endl;
    */

    //MANDIRI
    /*
        NAMA    : MUHAMMAD REZA ADI NUGRAHA
        NIM     : 1301204078
    */
    int pilihan;
    string kondisi;
    pilihan = menu();
    while (pilihan != 0){
        switch (pilihan){
        case 1:
            cout << "<<<<<<<<< INPUT DATA >>>>>>>>>" << endl;
            add_N_data(L);
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 2:
            cout << "<<<<<<<<< DATA PEGAWAI >>>>>>>>>" << endl;
            show_all_data(L);
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 3:
            cout << "<<<<<<<<< DATA PEGAWAI BERDASARKAN NIP >>>>>>>>>" << endl;
            cout << "Masukkan NIP yang ingin dicari: ";
            cin >> nip;
            P = search_by_nip(L, nip);
            cout << "Data NIP yang ingin dihapus:" << endl;
            cout << "Nama \t: " << info(P).nama << endl;
            cout << "NIP \t: " << info(P).nip << endl;
            cout << "Gaji \t: " << info(P).gaji << endl;
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 4:
            cout << "<<<<<<<<< HAPUS DATA >>>>>>>>>" << endl;
            cout << "Masukkan NIP yang ingin dihapus: ";
            cin >> nip;
            P = search_by_nip(L, nip);
            cout << "Data NIP yang ingin dihapus:" << endl;
            cout << "Nama \t: " << info(P).nama << endl;
            cout << "NIP \t: " << info(P).nip << endl;
            cout << "Gaji \t: " << info(P).gaji << endl;
            delete_Data(L, nip);
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 5:
            cout << "<<<<<<<<< JUMLAH PEGAWAI >>>>>>>>>" << endl;
            cout << "Jumlah pegawai \t: " << jumlah_pegawai(L) << " pegawai"<< endl;
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 6:
            cout << "<<<<<<<<< RATA-RATA PENGHASILAN >>>>>>>>>" << endl;
            cout << "Rata-rata penghasilan : Rp. " << (total_salary(L)/jumlah_pegawai(L)) << endl;
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        case 7:
            cout << "<<<<<<<<< PEGAWAI DENGAN GAJI TERTINGGI >>>>>>>>>" << endl;
            cout << "Nama pegawai dengan gaji tertinggi : " << max_gaji(L) << endl;
            cout << endl;
            cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
            break;
        }

        if (kondisi == "Y"){
            pilihan = menu();
        } else{
            pilihan = 0;
        }
    }

    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    return 0;
}
