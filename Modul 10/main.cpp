#include "MLL.h"

int main(){
    mll list_sales;
    sales info;
    adr_sales S;
    adr_jual J;

    createList(list_sales);

    info.nama = "Siska";
    info.golongan = "Gol A";
    new_elm_sales(info, S);
    inserLast_sales(list_sales, S);
    new_elm_jual(5, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(3, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(4, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(2, J);
    insert_new_penjualan(list_sales, S, J);

    info.nama = "Affan";
    info.golongan = "Gol C";
    new_elm_sales(info, S);
    inserLast_sales(list_sales, S);
    new_elm_jual(4, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(3, J);
    insert_new_penjualan(list_sales, S, J);

    info.nama = "Cahya";
    info.golongan = "Gol A";
    new_elm_sales(info, S);
    inserLast_sales(list_sales, S);
    new_elm_jual(5, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(0, J);
    insert_new_penjualan(list_sales, S, J);
    new_elm_jual(2, J);
    insert_new_penjualan(list_sales, S, J);

    info.nama = "Lia";
    info.golongan = "Gol C";
    new_elm_sales(info, S);
    inserLast_sales(list_sales, S);

    info.nama = "Hafidz";
    info.golongan = "Gol B";
    new_elm_sales(info, S);
    inserLast_sales(list_sales, S);
    new_elm_jual(7, J);
    insert_new_penjualan(list_sales, S, J);

    show_data_sales(list_sales);


    delete_penjualan(list_sales);

    show_data_sales(list_sales);

}
