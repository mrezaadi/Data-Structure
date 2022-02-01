#include "src.h"

int main()
{
    /*
    stack undoS, redoS;
    infotype x;

    createStack(undoS);
    createStack(redoS);

    push(undoS, "Data 1");
    push(undoS, "Data 2");
    push(undoS, "Data 3");
    push(undoS, "Data 4");
    push(undoS, "Data 5");
    cout << "<<<<<<<< DATA AWAL >>>>>>>>" << endl;
    show(undoS);

    cout << "<<<<<<<< POP >>>>>>>>" << endl;
    pop(undoS, x);
    show(undoS);

    cout << "<<<<<<<< UNDO >>>>>>>>" << endl;
    undo(undoS, redoS);
    cout << "STACK AKSI SETELAH UNDO" << endl;
    show(undoS);
    cout << "STACK REDO SETELAH UNDO" << endl;
    show(redoS);


    cout << "<<<<<<<< REDO >>>>>>>>" << endl;
    redo(redoS, undoS);
    cout << "STACK AKSI SETELAH REDO" << endl;
    show(undoS);
    cout << "STACK REDO SETELAH REDO" << endl;
    show(redoS);
    */

    Queue Q;
    address P;

    head(Q) = NULL;
    tail(Q) = NULL;

    createElm("STD", "MUHAMMAD",P);
    add(Q, P);
    createElm("PP", "REZA",P);
    add(Q, P);
    createElm("TP", "ADI",P);
    add(Q, P);
    createElm("RPL", "NUGRAHA",P);
    add(Q, P);
    showDaftarMK(Q);



}
