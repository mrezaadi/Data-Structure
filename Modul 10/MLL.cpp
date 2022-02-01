#include "MLL.h"

adr_sales searchSales(mll list_sales, string nama_sales){
    adr_sales P;
    P = first(list_sales);
    while (P != NULL && info(P).nama != nama_sales){
        P = next(P);
    }
    return P;
}

void inserLast_sales(mll &list_sales, adr_sales S){
    if (first(list_sales) == NULL){
        first(list_sales) = S;
    } else{
        adr_sales Q;
        Q = first(list_sales);
        while (next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = S;
    }
}

void createList(mll &list_sales){
    first(list_sales) = NULL;
}

void new_elm_sales(sales info, adr_sales &S){
    S = new elm_sales;
    info(S) = info;
    next(S) = NULL;
    next_jual(S) = NULL;
}

void new_elm_jual(int info, adr_jual &J){
    J = new elm_jual;
    info(J) = info;
    next(J) = NULL;
}

void insert_new_penjualan(mll &list_sales, adr_sales S, adr_jual J){
    adr_jual P;
    P = next_jual(S);
    if (P != NULL){
        while (next(P) != NULL){
            P = next(P);
        }
        next(P) = J;
    } else {
        next_jual(S) = J;
    }
}


void show_data_sales(mll list_sales){
    adr_sales P;
    adr_jual Q;
    P = first(list_sales);
    while (P != NULL){
        cout << info(P).nama << endl;
        Q = next_jual(P);
        while (Q != NULL){
            cout << info(Q) << " ";
            Q = next(Q);
        }
        cout << endl;
        P = next(P);
    }
}

void delete_first_penjualan(mll &list_sales, adr_sales S, adr_jual &J){
    if (next_jual(S) == NULL){
        cout << "Tidak ada penjualan" << endl;
    } else if (next(next_jual(S))== NULL){
        J = next_jual(S);
        next_jual(S) = NULL;
    } else {
        J = next_jual(S);
        next_jual(S) = next(J);
        next(J) = NULL;
    }
}

void delete_last_penjualan(mll &list_sales, adr_sales S, adr_jual &J){
    if (next_jual(S) == NULL){
        cout << "Tidak ada penjualan" << endl;
    } else if (next(next_jual(S))== NULL){
        J = next_jual(S);
        next_jual(S) = NULL;
    } else {
        adr_jual Q;
        Q = next_jual(S);
        while (next(next(Q)) != NULL){
            Q = next(Q);
        }
        J = next(Q);
        next(Q) = NULL;
        next(J) = NULL;
    }
}

void delete_after_penjualan(mll &list_sales, adr_sales S, adr_jual prec, adr_jual &J){
    next(prec) = next(J);
    next(J) = NULL;
}

void delete_penjualan(mll &list_penjualan){
    adr_sales P;
    P = first(list_penjualan);
    while (P != NULL){
        adr_jual Q;
        Q = next_jual(P);
        while (Q != NULL){
            if (info(Q)<3){
                adr_jual temp;
                if (next_jual(P)==Q){
                    delete_first_penjualan(list_penjualan, P, temp);
                } else if (next(Q) == NULL){
                    delete_last_penjualan(list_penjualan, P,temp);
                } else {
                    adr_jual prec;
                    prec = next_jual(P);
                    while (next(prec) != Q){
                        prec = next(prec);
                    }
                    delete_after_penjualan(list_penjualan, P, prec, temp);
                }
                Q = next(Q);
            }
            P = next(P);
        }
    }
}
