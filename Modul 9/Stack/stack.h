#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
#define top(S) S.top
#define info(S) S.info
using namespace std;

typedef int infotype;

struct stack{
    infotype info[10];
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype x);
int pop(stack &S);
void printInfo(stack S);
void ascending(stack &S);
void descending(stack &S);


#endif // STACK_H_INCLUDED
