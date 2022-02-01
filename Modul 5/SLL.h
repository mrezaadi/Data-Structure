#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#define nil NULL
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
/*
    NAMA    : MUHAMMAD REZA ADI NUGRAHA
    NIM     : 1301204078
*/
using namespace std;

struct pegawai{
    string nama, nip;
    int gaji;
};

typedef pegawai infotype;
typedef struct elmtPeg *address;

struct elmtPeg{
    infotype info;
    address next;
};

struct List{
    address first;
};

void create_list(List &L);
void insert_last(List &L, address P);
void delete_first(List &L, address &P);
void delete_after(List &L, address Prec, address &P);
void delete_last(List &L, address &P);
void new_element(pegawai peg, address &P);
void add_N_data(List &ListPeg);
void show_all_data(List ListPeg);
address search_by_nip(List ListPeg, string NIP);
void delete_Data(List &ListPeg, string NIP);
int jumlah_pegawai(List ListPeg);
int total_salary(List ListPeg);
string max_gaji(List ListPeg);
int menu();


#endif // SLL_H_INCLUDED
