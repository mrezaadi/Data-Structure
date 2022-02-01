#ifndef SRC_H_INCLUDED
#define SRC_H_INCLUDED

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

#include <iostream>
#define info_dosen(P) P->info_dosen
#define info_mhs(P) P->info_mhs
#define next_dosen(P) P->next_dosen
#define next_mhs(P) P->next_mhs
#define first(L) L.first
#define last(L) L.last

using namespace std;

struct dosen {
    string nama_dosen;
    string kepakaran;
    int jumlah_bimbingan;
};
struct mhs {
    string nama_mhs;
    string nim;
    string topik;
    int jumlah_sks;
};

typedef struct elm_dosen *adr_dosen;
typedef struct elm_mhs *adr_mhs;

//LIST DOSEN DENGAN LAST (PARENT)
struct list_dosen{
    adr_dosen first;
    adr_dosen last;
};

//LIST MAHASISWA DENGAN LAST (CHILD)
struct list_mhs{
    adr_mhs first;
    adr_mhs last;
};

struct elm_dosen{
    dosen info_dosen;
    adr_dosen next_dosen;
    adr_mhs next_mhs;
};

struct elm_mhs{
    mhs info_mhs;
    adr_mhs next_mhs;
};

//SPESIFIKASI FUNGSIONALITAS

void create_list_dosen(list_dosen &Ldosen);
void create_list_mhs(list_mhs &Lmhs);
void new_elm_dosen(dosen data, adr_dosen &D);
void new_elm_mhs(mhs data, adr_mhs &M);
void search_dosen(list_dosen Ldosen, adr_dosen &D, string nama);
void search_mhs(list_mhs Lmhs, adr_mhs &M ,string nama);
int jumlah_pembimbing_mahasiswa(list_dosen Ldosen, string nama);

void add_dosen(list_dosen &Ldosen, adr_dosen D);
void delete_dosen(list_dosen &Ldosen, string nama);
void add_mhs(list_dosen &Ldosen, adr_dosen &D, adr_mhs &M);
void delete_mhs(list_dosen &Ldosen, string nama);
void remove_relation(list_dosen &Ldosen, string nama_dosen, string nama_mahasiswa);
void plus_jumlah_bimbingan(adr_dosen &D);
void minus_jumlah_bimbingan(adr_dosen &D);

void show_dosen_dan_jumlah_bimbingan(list_dosen Ldosen);
void show_mahasiwa_bimbingan_dosen(list_dosen Ldosen, string nama_dosen);
void show_mahasiswa_topik(list_dosen Ldosen, string topik);
void show_all(list_dosen Ldosen);
void show_dosen_tersedia(list_dosen Ldosen);
int hitung_jumlah_mahasiswa(list_dosen Ldosen);

int selectMenu();

#endif // SRC_H_INCLUDED
