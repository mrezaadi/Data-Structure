#include "src.h"

/*
    NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
    KELAS   : IF-44-05
*/

/*
    NAMA    : LISYANA DAMAYANTI
    NIM     : 1301204024
    KELAS   : IF-44-05
*/

int main(){
    adr_dosen D;
    adr_mhs M;
    list_dosen Ldosen;
    list_mhs Lmhs;
    dosen data_dosen;
    mhs data_mhs;

    create_list_dosen(Ldosen);
    int pilihan;
    char kondisi;

    pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
            case 1:{
                cout << "Inputkan data dibawah ini!" << endl;
                cout << "Nama Dosen \t : ";
                cin >> data_dosen.nama_dosen;
                cout << "Kepakaran \t : ";
                cin >> data_dosen.kepakaran;
                data_dosen.jumlah_bimbingan = 0;
                new_elm_dosen(data_dosen, D);
                add_dosen(Ldosen, D);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 2:{
                string nama_dosen;
                cout << "Inputkan nama dosen yang ingin dihapus!" << endl;
                cout << "Nama Dosen \t : ";
                cin >> nama_dosen;
                delete_dosen(Ldosen, nama_dosen);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 3:{
                cout << "Inputkan data dibawah ini!" << endl;
                cout << "Nama Mahasiswa \t: ";
                cin >> data_mhs.nama_mhs;
                cout << "NIM \t\t: ";
                cin >> data_mhs.nim;
                cout << "Topik \t\t: ";
                cin >> data_mhs.topik;
                cout << "SKS \t\t: ";
                cin >> data_mhs.jumlah_sks;
                new_elm_mhs(data_mhs, M);
                cout << endl;

                string nama_dosen;
                cout << "Nama Dosen \t: ";
                cin >> nama_dosen;
                search_dosen(Ldosen,D,nama_dosen);

                add_mhs(Ldosen, D, M);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 4:{
                string data;
                cout << "Inputkan nama mahasiswa!" << endl;
                cout << "Nama Mahsiswa \t: ";
                cin >> data;
                delete_mhs(Ldosen, data);

                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 5:{
                string nama_mhs;
                cout << "Inputkan nama mahasiswa!" << endl;
                cout << "Nama Mahsiswa \t : ";
                cin >> nama_mhs;

                string nama_dosen;
                cout << "Inputkan nama dosen!" << endl;
                cout << "Nama Dosen \t : ";
                cin >> nama_dosen;

                remove_relation(Ldosen, nama_dosen, nama_mhs);

                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 6:{
                show_dosen_dan_jumlah_bimbingan(Ldosen);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 7:{
                string nama_dosen;
                cout << "Inputkan nama dosen!" << endl;
                cout << "Nama Dosen \t : ";
                cin >> nama_dosen;
                show_mahasiwa_bimbingan_dosen(Ldosen, nama_dosen);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 8:{
                string topik;
                cout << "Inputkan topik!" << endl;
                cout << "Topik : ";
                cin >> topik;
                show_mahasiswa_topik(Ldosen, topik);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 9:{
                show_dosen_tersedia(Ldosen);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 10:{
                cout << "Jumlah mahasiswa mengambil TA: ";
                cout << hitung_jumlah_mahasiswa(Ldosen) << endl;
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
            case 11:{
                show_all(Ldosen);
                cout << "Kembali ke menu utama?(Y/N): "; cin >> kondisi;
                break;
            }
        }
        if (kondisi == 'Y'){
            pilihan = selectMenu();
        } else {
            pilihan = 0;
        }
    }
}
