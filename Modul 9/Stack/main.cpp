#include "stack.h"

int main()
{
    stack S;
    createStack(S);
    /*
    push(S, 2);
    push(S, 3);
    push(S, 4);
    push(S, 5);
    printInfo(S);
    pop(S);
    printInfo(S);
    */

    push(S, 12);
    push(S, 17);
    push(S, 5);
    push(S, 10);
    push(S, 15);
    push(S, 25);
    push(S, 11);
    push(S, 22);
    push(S, 19);
    printInfo(S);
    ascending(S);
    printInfo(S);
    descending(S);
    printInfo(S);
}
