#include "src.h"

//STACK
bool isEmpty(stack S){
    return (top(S) == -1);
}

bool isFull(stack S){
    return (top(S) == nMax);
}

void createStack(stack &S){
    top(S) = -1;
}

void push(stack &S, infotype x){
    if (isFull(S) == false){
        top(S) = top(S)+1;
        info(S)[top(S)] = x;
    }
}

void pop(stack &S, infotype &x){
    if (isEmpty(S) == false){
        x = info(S)[top(S)];
        top(S) = top(S)-1;
    }
}

void undo(stack &undoS, stack &redoS){
    infotype x;
    pop(undoS, x);
    push(redoS, x);
}

void redo(stack &redoS, stack &undoS){
    infotype x;
    pop(redoS, x);
    push(undoS, x);
}

void show(stack S){
    int i;
    for (i=top(S); i>=0; i--){
        cout << info(S)[i] << endl;
    }
    cout << endl;
}

//QUEUE
void createElm(string kode, string dosen, address &P){
    P = new elmQueue;
    kodeMK(P) = kode;
    namaDosen(P) = dosen;
    next(P) = NULL;
}

void add(Queue &Q, address P){
    if (head(Q) == NULL){
        head(Q) = P;
        tail(Q) = P;
    } else {
        next(tail(Q)) = P;
        tail(Q) = next(tail(Q));
    }
}

void showDaftarMK(Queue Q){
    address P;
    int urutan = 1;
    P = head(Q);
    while (P != NULL){
        cout << "[" << urutan << "]" << endl;
        cout << "Kode MK \t: " << kodeMK(P) << endl;
        cout << "Nama Dosen \t: " << namaDosen(P) << endl;
        P = next(P);
        urutan++;
    }
}




