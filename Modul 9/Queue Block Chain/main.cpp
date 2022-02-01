#include "Queue.h"

using namespace std;

int main()
{
    address data_transaksi;
    address P;
    Queue Q;

    //Buat Queue baru
    head(Q) = NULL;

    //Transaksi
    P = createElmt("Andi Transfer Doni 50.000");
    masukkan_transaksi(Q,data_transaksi);
    P = createElmt("Doni Transfer Saras 10.000");
    masukkan_transaksi(Q,data_transaksi);
    P = createElmt("Tono Transfer Bili 20.000");
    masukkan_transaksi(Q,data_transaksi);
    transaksi(Q, data_transaksi);
    printQueue(Q);
}
