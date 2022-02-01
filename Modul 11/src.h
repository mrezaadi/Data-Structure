#ifndef SRC_H_INCLUDED
#define SRC_H_INCLUDED

#include <iostream>
#define top(S) S.top
#define info(S) S.info

using namespace std;

//STACK ARRAY
const int nMax = 10;
const int nil = 0;
typedef string infotype;


struct stack{
    infotype info[nMax];
    int top;
};

bool isEmpty(stack S);
bool isFull(stack S);
void createStack(stack &S);
void push(stack &S, infotype x);
void pop(stack &S, infotype &x);
void undo(stack &undoS, stack &redoS);
void redo(stack &redoS, stack &undoS);
void show(stack S);


//QUEUE
#define kodeMK(P) P->kodeMK
#define namaDosen(P) P->namaDosen
#define next(P) P->next
#define head(Q) Q.head
#define tail(Q) Q.tail

typedef struct elmQueue *address;

struct elmQueue{
    string kodeMK;
    string namaDosen;
    address next;
};

struct Queue {
    address head;
    address tail;
};

void add(Queue &Q, address P);
void showDaftarMK(Queue Q);
void createElm(string kode, string dosen, address &P);


#endif // SRC_H_INCLUDED
