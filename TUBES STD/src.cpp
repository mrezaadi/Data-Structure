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

void create_list_dosen(list_dosen &Ldosen){
    //Buat list dengan cara memberikan nilai NULL pada first dan last nya
    first(Ldosen) = NULL;
    last(Ldosen) = NULL;
}

void create_list_mhs(list_mhs &Lmhs){
    //Buat list dengan cara memberikan nilai NULL pada first dan last nya
    first(Lmhs) = NULL;
    last(Lmhs) = NULL;
}

void new_elm_dosen(dosen data, adr_dosen &D){

    //Buat elemen dosen
    D = new elm_dosen;
    //Jumlah bimbingan awal adalah 0
    data.jumlah_bimbingan = 0;
    //Masukkan data dosen ke dalam info
    info_dosen(D) = data;
    //NULL kan next_mhs dan next_dosen karena belum diberikan hubungan
    next_dosen(D) = NULL;
    next_mhs(D) = NULL;
}

void new_elm_mhs(mhs data, adr_mhs &M){
    //Buat elemen mahasiswa
    M = new elm_mhs;
    //Masukkan data mahasiswa ke dalam info
    info_mhs(M) = data;
    //NULL kan next_mhs karena belum diberikan hubungan
    next_mhs(M) = NULL;
}

void search_dosen(list_dosen Ldosen, adr_dosen &D ,string nama){
    //Sisipkan adr_mhs D ke first list_dosen
    D = first(Ldosen);
    //Lakukan perulangan sampai kondisi D == NULL
    while (D != NULL){
        //Jika nama_dosen sama dengan parameter yang diberikan maka perulangan berhenti
        if (info_dosen(D).nama_dosen == nama){
            break;
        }
        D = next_dosen(D);
    }
}

void search_mhs(list_mhs Lmhs, adr_mhs &M, string nama){
    //Sisipkan adr_mhs M ke first list_mhs
    M = first(Lmhs);
    //Lakukan perulangan sampai kondisi M == NULL
    while (M != NULL){
        //Jika nama_mhs sama dengan parameter yang diberikan maka perulangan berhenti
        if (info_mhs(M).nama_mhs == nama){
            break;
        }
        M = next_mhs(M);
    }
}

int jumlah_pembimbing_mahasiswa(list_dosen Ldosen, string nama){
    adr_dosen D;
    adr_mhs M;
    int jumlah = 0;

    //Sisipkan adr_mhs D ke first list_dosen
    D = first(Ldosen);
    while (D != NULL){
        //Cek mahasiswa bimbingan dosen
        M = next_mhs(D);
        while (M != NULL){
            //Jika ditemukan, maka jumlah bertambah 1
            if (info_mhs(M).nama_mhs == nama){
                jumlah++;
            }
            M = next_mhs(M);
        }
        D = next_dosen(D);
    }
    return jumlah;
}

void add_dosen(list_dosen &Ldosen, adr_dosen D){
    //Gunakan insert_last

    //Kondisi saat list kosong
    if (first(Ldosen) == NULL){
        first(Ldosen) = D;
        last(Ldosen) = D;
    //Kondisi lainnya
    } else {
        next_dosen(last(Ldosen)) = D;
        last(Ldosen) = D;
    }
}

void delete_dosen(list_dosen &Ldosen, string nama){
    adr_dosen D;
    //Ubah D menjadi elemen dosen yang memiliki nama sesuai dengan parameter
    search_dosen(Ldosen,D, nama);
    adr_mhs M;
    M = next_mhs(D);
    //Hapus semua mahasiswa dibimbing
    while (next_mhs(D) != NULL){
        //Ubah next_mhs(D) ke next_mhs selanjutnya
        next_mhs(D) = next_mhs(next_mhs(D));
        //NULL kan next_mhs(M)
        next_mhs(M) = NULL;
        //Delete M
        delete M;
        //Ubah M ke next_mhs D yang udah diubah sebelumnya
        M = next_mhs(D);
    }

    //Jika ada satu elemen
    if (D == first(Ldosen) && D == last(Ldosen)){
        first(Ldosen) = NULL;
        last(Ldosen) = NULL;
        delete D;
    //Delete first
    } else if (D == first(Ldosen)){
        first(Ldosen) = next_dosen(first(Ldosen));
        next_dosen(D) = NULL;
        delete D;
    //Delete last
    } else if (D == last(Ldosen)){
         adr_dosen P;
         P = first(Ldosen);
         while (next_dosen(P)!= last(Ldosen)){
            P = next_dosen(P);
         }
         last(Ldosen) = P;
         next_dosen(P) = NULL;
         delete D;
    //Delete after
    } else {
         adr_dosen prec;
         prec = first(Ldosen);
         while (next_dosen(prec)!= D){
            prec = next_dosen(prec);
         }
         next_dosen(prec) = next_dosen(D);
         next_dosen(D) = NULL;
         delete D;
    }
}

void add_mhs(list_dosen &Ldosen, adr_dosen &D, adr_mhs &M){
    int jumlah_pembimbing;
    jumlah_pembimbing = jumlah_pembimbing_mahasiswa(Ldosen, info_mhs(M).nama_mhs);
    bool found = false;

    adr_mhs P;
    P = next_mhs(D);

    //Cek apakah sudah ada mahasiswa yang sama yang dibimbing oleh dosen pembimbing
    while(P != NULL && found==false ){
        if (info_mhs(P).nama_mhs == info_mhs(M).nama_mhs){
            found = true;
        }
        P = next_mhs(P);
    }

    //Pengecekan syarat
    if (info_mhs(M).jumlah_sks >= 120 && info_mhs(M).topik == info_dosen(D).kepakaran && info_dosen(D).jumlah_bimbingan <10 && jumlah_pembimbing != 2 && found == false){
        //Jika list kosong
        if (next_mhs(D)==NULL){
            next_mhs(D) = M;
            plus_jumlah_bimbingan(D);
        //Insert last
        } else {
            list_mhs Lmhs;
            create_list_mhs(Lmhs);
            //Cari elemen last
            adr_mhs P;
            first(Lmhs) = next_mhs(D);
            P = first(Lmhs);
            while (next_mhs(P) != NULL){
                P = next_mhs(P);
            }
            last(Lmhs) = P;
            next_mhs(last(Lmhs)) = M;
            last(Lmhs) = M;
            plus_jumlah_bimbingan(D);
        }
    }
}

void delete_mhs(list_dosen &Ldosen, string nama_mahasiswa){
    adr_dosen D;
    D = first(Ldosen);
    //Mengecek semua elemen dosen
    while (D != NULL){
        //Lakukan penghapusan jika dosen memiliki mahasiswa bimbingan
        if (next_mhs(D)!= NULL){
            adr_mhs M;
            list_mhs Lmhs;
            create_list_mhs(Lmhs);

            M = next_mhs(D);
            first(Lmhs) = M;
            last(Lmhs) = M;

            //Tentukan last dari mahasiswa bimbingan dosen
            adr_mhs Q;
            Q = first(Lmhs);
            while (next_mhs(Q) != NULL){
                Q = next_mhs(Q);
            }
            last(Lmhs) = Q;
            //Cari posisi mahasiswa yang ingin dihaps
            search_mhs(Lmhs, M, nama_mahasiswa);
            if (M != NULL){
                //Satu elemen
                if (M == first(Lmhs) && M == last(Lmhs)){
                    next_mhs(D) = NULL;
                    next_mhs(M) = NULL;
                    minus_jumlah_bimbingan(D);
                    delete M;
                //Delete first
                } else if (M == first(Lmhs)){
                    next_mhs(D) = next_mhs(first(Lmhs));
                    next_mhs(M) = NULL;
                    minus_jumlah_bimbingan(D);
                    delete M;
                //Delete last
                } else if (M == last(Lmhs)){
                    Q = first(Lmhs);
                    while (next_mhs(Q) != last(Lmhs)){
                        Q = next_mhs(Q);
                    }
                    last(Lmhs) = Q;
                    next_mhs(last(Lmhs)) = NULL;
                    next_mhs(M) = NULL;
                    minus_jumlah_bimbingan(D);
                    delete M;
                //Delete after
                } else {
                    Q = first(Lmhs);
                    while (next_mhs(Q) != M){
                        Q = next_mhs(Q);
                    }
                    next_mhs(Q) = next_mhs(M);
                    next_mhs(M) = NULL;
                    minus_jumlah_bimbingan(D);
                    delete M;
                }
            }
        }
        D = next_dosen(D);
    }
}

void remove_relation(list_dosen &Ldosen, string nama_dosen, string nama_mahasiswa){
    adr_dosen D;
    D = first(Ldosen);
    //Cari posisi dosen
    search_dosen(Ldosen, D, nama_dosen);
    //Lakukan penghapusan jika dosen memiliki mahasiwa bimbingan
    if (next_mhs(D)!= NULL){
        adr_mhs M;
        list_mhs Lmhs;
        create_list_mhs(Lmhs);

        M = next_mhs(D);
        first(Lmhs) = M;
        last(Lmhs) = M;

        //Tentukan last dari mahasiswa bimbingan dosen
        adr_mhs Q;
        Q = first(Lmhs);
        while (next_mhs(Q) != NULL){
            Q = next_mhs(Q);
        }
        last(Lmhs) = Q;
        search_mhs(Lmhs, M, nama_mahasiswa);
        if (M != NULL){
            //Satu elemen
            if (M == first(Lmhs) && M == last(Lmhs)){
                next_mhs(D) = NULL;
                next_mhs(M) = NULL;
                minus_jumlah_bimbingan(D);
                delete M;
            //Delete first
            } else if (M == first(Lmhs)){
                next_mhs(D) = next_mhs(first(Lmhs));
                next_mhs(M) = NULL;
                minus_jumlah_bimbingan(D);
                delete M;
            //Delete last
            } else if (M == last(Lmhs)){
                Q = first(Lmhs);
                while (next_mhs(Q) != last(Lmhs)){
                    Q = next_mhs(Q);
                }
                last(Lmhs) = Q;
                next_mhs(last(Lmhs)) = NULL;
                next_mhs(M) = NULL;
                minus_jumlah_bimbingan(D);
                delete M;
            //Delete after
            } else {
                Q = first(Lmhs);
                while (next_mhs(Q) != M){
                    Q = next_mhs(Q);
                }
                next_mhs(Q) = next_mhs(M);
                next_mhs(M) = NULL;
                minus_jumlah_bimbingan(D);
                delete M;
            }
        }
    }
}

void plus_jumlah_bimbingan(adr_dosen &D){
    //Tambah 1 jumlah bimbingan dosen
    info_dosen(D).jumlah_bimbingan++;
}

void minus_jumlah_bimbingan(adr_dosen &D){
    //Kurang 1 jumlah bimbingan dosen
    info_dosen(D).jumlah_bimbingan--;
}

void show_dosen_dan_jumlah_bimbingan(list_dosen Ldosen){
    adr_dosen D;
    int urutan = 1;

    D = first(Ldosen);
    while (D != NULL){
        cout << "[" << urutan << "]" << endl;
        cout << "Nama Dosen \t : " << info_dosen(D).nama_dosen << endl;
        cout << "Jumlah bimbingan : " << info_dosen(D).jumlah_bimbingan << endl;
        cout << endl;
        urutan++;
        D = next_dosen(D);
    }

}

void show_mahasiwa_bimbingan_dosen(list_dosen Ldosen, string nama_dosen){
    adr_dosen D;
    search_dosen(Ldosen, D, nama_dosen);
    int urutan = 1;

    adr_mhs M;
    M = next_mhs(D);
    while (M != NULL){
        cout << "[" << urutan << "]" << endl;
        cout << "Nama \t: " << info_mhs(M).nama_mhs << endl;
        cout << "NIM \t: " << info_mhs(M).nim << endl;
        cout << "Topik \t: " << info_mhs(M).topik << endl;
        cout << "SKS \t: " << info_mhs(M).jumlah_sks << endl;
        cout << endl;
        urutan++;
        M = next_mhs(M);
    }
}

void show_mahasiswa_topik(list_dosen Ldosen, string topik){
    adr_dosen D;
    D = first(Ldosen);
    int urutan = 1;
    while (D != NULL){
        adr_mhs M;
        M = next_mhs(D);
        while (M != NULL){
            if (info_mhs(M).topik == topik){
                cout << "[" << urutan << "]" << endl;
                cout << "Nama \t: " << info_mhs(M).nama_mhs << endl;
                cout << "NIM \t: " << info_mhs(M).nim << endl;
                cout << "Topik \t: " << info_mhs(M).topik << endl;
                cout << "SKS \t: " << info_mhs(M).jumlah_sks << endl;
                cout << endl;
                urutan++;
            }
            M = next_mhs(M);
        }
        D = next_dosen(D);
    }
}

void show_all(list_dosen Ldosen){
    adr_dosen D;
    D = first(Ldosen);
    int urutan_dosen = 1;


    while (D != NULL){
        cout << "[" << urutan_dosen << "]" << endl;
        cout << "Nama Dosen \t : " << info_dosen(D).nama_dosen << endl;
        cout << "Kepakaran \t : " << info_dosen(D).kepakaran << endl;
        cout << "Jumlah bimbingan : " << info_dosen(D).jumlah_bimbingan << endl;
        urutan_dosen++;
        adr_mhs M;
        M = next_mhs(D);
        int urutan_mhs = 1;
        while (M != NULL){
            cout << "\t[" << urutan_mhs << "]" << endl;
            cout << "\tNama \t: " << info_mhs(M).nama_mhs << endl;
            cout << "\tNIM \t: " << info_mhs(M).nim << endl;
            cout << "\tTopik \t: " << info_mhs(M).topik << endl;
            cout << "\tSKS \t: " << info_mhs(M).jumlah_sks << endl;
            cout << endl;
            urutan_mhs++;
            M = next_mhs(M);
        }
        D = next_dosen(D);
    }
}

void show_dosen_tersedia(list_dosen Ldosen){
    adr_dosen D;
    D = first(Ldosen);
    int urutan_dosen = 1;
    while (D != NULL){
        if (info_dosen(D).jumlah_bimbingan <10){
            cout << "[" << urutan_dosen << "]" << endl;
            cout << "Nama Dosen \t : " << info_dosen(D).nama_dosen << endl;
            cout << "Kepakaran \t : " << info_dosen(D).kepakaran << endl;
            cout << "Jumlah bimbingan : " << info_dosen(D).jumlah_bimbingan << "/10" <<endl;
            urutan_dosen++;
        }
        D = next_dosen(D);
    }
}

int hitung_jumlah_mahasiswa(list_dosen Ldosen){
    adr_dosen D;
    D = first(Ldosen);
    int jumlah = 0;
    int sama = 0;
    while (D != NULL){
        adr_mhs M;
        M = next_mhs(D);
        while (M != NULL){
            //Untuk cek mahasiswa yang memiliki 2 dosen bimbingan
            if (jumlah_pembimbing_mahasiswa(Ldosen, info_mhs(M).nama_mhs) == 2){
                sama++;
            } else{
                jumlah++;
            }
            M = next_mhs(M);
        }
        D = next_dosen(D);
    }
    //Yang sama dibagi dua, sehingga cuma 1 dihitungnya
    sama = sama/2;
    return jumlah+sama;
}

int selectMenu(){
    cout << "+===================== MENU UTAMA ======================+" << endl;
    cout << "|1. Tambah data dosen                                   |" << endl;
    cout << "|2. Hapus data dosen                                    |" << endl;
    cout << "|3. Tambah data mahasiswa                               |" << endl;
    cout << "|4. Hapus data mahasiswa                                |" << endl;
    cout << "|5. Hapus hubungan mahasiswa dan dosen                  |" << endl;
    cout << "|6. Tampilkan jumlah bimbingan tiap dosen               |" << endl;
    cout << "|7. Tampilkan mahasiswa bimbingan dosen                 |" << endl;
    cout << "|8. Tampilkan mahasiswa yang mengambil topik tertentu   |" << endl;
    cout << "|9. Tampilkan dosen yang masih tersedia                 |" << endl;
    cout << "|10. Tampilkan jumlah mahasiswa TA                      |" << endl;
    cout << "|11. Tampilkan semua data                               |" << endl;
    cout << "|0. Exit                                                |" << endl;
    cout << "+=======================================================+" << endl;

    cout << "Pilihan menu: ";

    int input;
    cin >> input;
    cout << endl;
    return input;
}
