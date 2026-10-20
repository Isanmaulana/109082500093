#include "Singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address baru = new ElmList;
    baru->info = x;
    baru->next = Nil;
    return baru;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address bantu = L.First;
    while (bantu != Nil) {
        cout << bantu->info << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}