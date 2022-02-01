#include "stack.h"

void createStack(stack &S){
    top(S) = -1;
}

bool isEmpty(stack S){
    if (top(S) == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(stack S){
    if (top(S) == 9){
        return true;
    } else {
        return false;
    }
}

void push(stack &S, infotype x){
    if (isFull(S) == false){
        top(S) = top(S)+1;
        info(S)[top(S)] = x;
    }
}

int pop(stack &S){
    infotype x;
    x = info(S)[top(S)];
    top(S) = top(S) - 1;
    return x;
}

void printInfo(stack S){
    int i;
    for (i=top(S); i>=0; i--){
        cout << info(S)[i] << " ";
    }
    cout << endl;
}

void ascending(stack &S){
    int pass, i, temp;
    i = 0;
    pass = 1;
    while (pass < 10){
        temp = info(S)[pass];
        i = pass;
        while (i > 0 && temp < info(S)[i-1]){
            info(S)[i] = info(S)[i-1];
            i = i - 1;
        }
        info(S)[i] = temp;
        pass = pass + 1;
    }
}

void descending(stack &S){
    int pass, i, temp;
    i = 0;
    pass = 1;
    while (pass < 10){
        temp = info(S)[pass];
        i = pass;
        while (i > 0 && temp > info(S)[i-1]){
            info(S)[i] = info(S)[i-1];
            i = i - 1;
        }
        info(S)[i] = temp;
        pass = pass + 1;
    }
}
