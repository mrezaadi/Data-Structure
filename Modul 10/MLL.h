#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
#define info(P) P->info
#define next(P) P->next
#define next_jual(P) P->next_jual
#define first(L) L.first

using namespace std;

//JUAL
typedef struct elm_jual *adr_jual;
struct elm_jual{
    int info;
    adr_jual next;
};

//SALES
struct sales{
    string nama;
    string golongan;
};

typedef struct elm_sales *adr_sales;
struct elm_sales {
    sales info;
    adr_sales next;
    adr_jual next_jual;
};
struct mll{
    adr_sales first;
};

//FUNGSI PROSEDUR
adr_sales searchSales(mll list_sales, string nama_sales);
void inserLast_sales(mll &list_sales, adr_sales S);
void createList(mll &list_sales);
void new_elm_sales(sales info, adr_sales &S);
void new_elm_jual(int info, adr_jual &J);
void insert_new_penjualan(mll &list_sales, adr_sales S, adr_jual J);
void show_data_sales(mll list_sales);
void delete_first_penjualan(mll &list_sales, adr_sales S, adr_jual &J);
void delete_last_penjualan(mll &list_sales, adr_sales S, adr_jual &J);
void delete_after_penjualan(mll &list_sales, adr_sales S, adr_jual prec, adr_jual &J);
void delete_penjualan(mll &list_penjualan);


#endif // MLL_H_INCLUDED
