#include "DLL_First_Last.h"

int main(){
    List L;
    address temp;

    createList(L);
    printList(L);


    insertAscending(L,25);
    printList(L);


    insertAscending(L,10);
    printList(L);

    insertAscending(L,32);
    printList(L);

    insertAscending (L,3);
    printList(L);

    deleteElemen(L,32);
    printList(L);

    deleteElemen(L,3);
    printList(L);

    deleteElemen(L,10);
    printList(L);

    deleteElemen(L,25);
    printList(L);

    insertAscending(L, 25);
    printList(L);

    insertAscending(L, 10);
    printList(L);

    insertAscending(L, 10);
    printList(L);

    insertAscending(L, 25);
    printList(L);

    insertAscending(L, 25);
    printList(L);

    cout << findElement(L, 10) << endl;
    cout << frequencyOfElm(L,10) << endl;
    cout << frequencyOfElm(L,25) << endl;
    cout << frequencyOfElm(L, 2) << endl;
}
