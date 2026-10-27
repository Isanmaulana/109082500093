# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ichsan Maulana Muhammad - 109082500093</p>

## Dasar Teori

1. Singly Linked List
Singly Linked List merupakan struktur data yang terdiri dari beberapa node yang saling terhubung melalui pointer. Setiap node memiliki bagian info untuk menyimpan data dan next untuk mengarah ke node berikutnya. Node pertama ditandai dengan pointer First, sedangkan node terakhir memiliki pointer next bernilai Nil. Struktur ini memudahkan penambahan dan penghapusan data karena tidak memerlukan penyimpanan yang berurutan di memori.

2. Pencarian Data pada Linked List
Pencarian data pada Singly Linked List dilakukan dengan memeriksa setiap node secara berurutan, dimulai dari node pertama. Pointer digunakan untuk berpindah ke node selanjutnya sampai data yang diinginkan ditemukan atau seluruh node telah diperiksa. Fungsi findElm() dapat digunakan untuk menemukan node berdasarkan nilai tertentu. Jika data ditemukan, program akan memberikan informasi bahwa data tersedia, begitu pula sebaliknya.

3. Pembaruan Data pada Linked List
Pembaruan data bertujuan mengubah informasi yang tersimpan dalam node tanpa perlu menghapus node tersebut. Prosesnya dilakukan dengan menentukan node yang ingin diperbarui, kemudian mengganti nilai data sesuai kebutuhan. Pada data mahasiswa, perubahan dapat dilakukan berdasarkan posisi node maupun NIM. Beberapa fungsi yang dapat digunakan adalah updateFirst(), updateLast(), updateAfter(), dan updateByNim(). Dengan cara ini, informasi dapat diperbarui tanpa mengubah susunan hubungan antar-node.

4. Penelusuran Node Menggunakan Pointer
Penelusuran node adalah proses mengakses node satu per satu dengan mengikuti arah pointer next. Proses ini dimulai dari First dan dilanjutkan hingga node yang dibutuhkan ditemukan atau mencapai akhir list yang ditandai dengan Nil. Penelusuran sangat berguna dalam pencarian maupun pembaruan data, terutama ketika posisi node belum diketahui. Penggunaan pointer yang tepat juga membantu mencegah kesalahan saat mengakses node dalam linked list.


## Guided

### 1. Header list

```C++
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);

void updateFirst(linkedlist &list);
void updateLast(linkedlist &list);
void updateAfter(linkedlist list, address &prev);
void updateByNim(linkedlist &list, string nim);

address FindNodeByData(linkedlist List, string data);
void FindNodeByAddress(linkedlist List, address node);
void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir);
#endif
```

penjelasan singkat guided 1
Header List.h berisi deklarasi struktur data dan fungsi untuk mengelola Singly Linked List. Struktur mahasiswa menyimpan nama, NIM, dan umur, sedangkan node menyimpan data mahasiswa serta pointer next. Struktur linkedlist memiliki pointer first sebagai penunjuk node pertama. Header ini juga mendeklarasikan fungsi untuk menambah, menghapus, menampilkan, menghitung, memperbarui, dan mencari node dalam linked list.

### 2. list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}

// prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List Kosong" << endl;
    } else{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;
    list.first->isidata = newData;
    }
}

void updateLast(linkedlist &list)
{
    if (isEmpty(list) == true)
    {
        cout << "List Kosong" << endl;
    } else{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    address nodeBantu = list.first;
    while (nodeBantu->next != Nil)
    {
        nodeBantu = nodeBantu->next;
    }

    nodeBantu->isidata = newData;
    }
}

void updateAfter(linkedlist list, address &prev)
{
    if (isEmpty(list) == true)
    {
        cout << "List Kosong" << endl;
    } else{
    dataMahasiswa newData;
    cout << "Masukan nama baru : ";
    cin >> newData.nama;
    cout << "Masukan nim baru : ";
    cin >> newData.nim;
    cout << "Masukan umur baru : ";
    cin >> newData.umur;

    prev->next->isidata = newData;
    }
}

void updateByNim(linkedlist &list, string nim)
{
    if (!isEmpty(list))
    {
        address nodeBantu = FindNodeByData(list, nim);

        if (nodeBantu != Nil)
        {
        dataMahasiswa newData;
        cout << "Masukan nama baru : ";
        cin >> newData.nama;
        cout << "Masukan nim baru : ";
        cin >> newData.nim;
        cout << "Masukan umur baru : ";
        cin >> newData.umur;

            nodeBantu->isidata = newData;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// prosedur-prosedur untuk searching data didalam list
address FindNodeByData(linkedlist List, string data)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan nama atau nim yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu -> isidata.nama == data || nodeBantu -> isidata.nim == data)
            {
                // cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                // cout << "Nama : " << nodeBantu -> isidata.nama << ", NIM : " << nodeBantu -> isidata.nim << ", Usia : " << nodeBantu -> isidata.umur << endl;
                found = true;
                return nodeBantu;
            }
            nodeBantu = nodeBantu = nodeBantu ->next;
        }
        if (found = false)
        {
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
    return Nil;
}

void FindNodeByAddress(linkedlist List, address node)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan node yang sesuai dengan alamat yang dicari */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil)
        {
            posisi++;
            if (nodeBantu == node)
            {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat Node : " << nodeBantu << endl;
                cout << "Nama : " << nodeBantu -> isidata.nama << ", NIM : " << nodeBantu -> isidata.nim << ", Usia : " << nodeBantu -> isidata.umur << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu -> next;
        }
        if (found == false)
        {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

void FindNodeByRange(linkedlist List, int nilaiAwal, int nilaiAkhir)
{
    /* I.S. list mungkin kosong
       F.S. menampilkan semua node yang memiliki umur di dalam rentang nilaiAwal sampai nilaiAkhir */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Data diatas usia " << nilaiAwal << " dan dibawah " << nilaiAkhir << " ---" << endl;
        while (nodeBantu != Nil)
        {
            posisi++;
            int umur = nodeBantu -> isidata.umur;
            if (umur >= nilaiAwal && umur <= nilaiAkhir)
            {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama : " << nodeBantu -> isidata.nama << ", NIM : " << nodeBantu -> isidata.nim << ", Usia : " << nodeBantu -> isidata.umur << endl;
                found = true;
            }
            nodeBantu = nodeBantu -> next;
        }
        if (found == false)
        {
            cout << "Tidak ada data node dalam range tersebut!" << endl;
        }
    }
}
```

penjelasan singkat guided 2
File List.cpp berisi implementasi fungsi untuk mengelola Singly Linked List mahasiswa, mulai dari membuat list, menambah dan menghapus node, hingga menampilkan dan menghitung jumlah data. Selain itu, terdapat fungsi untuk memperbarui informasi mahasiswa berdasarkan posisi atau NIM, serta mencari node berdasarkan nama, NIM, alamat, dan rentang umur. Pointer digunakan untuk menghubungkan dan menelusuri node, sedangkan alokasi dan dealokasi memori digunakan untuk mengatur pembuatan serta penghapusan node.

### 3. main.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

int main(){
	linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE FIRST ---" << endl;
    printList(List);

    updateLast(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE LAST ---" << endl;
    printList(List);

    updateAfter(List, nodeC);
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE AFTER NODE C ---" << endl;
    printList(List);

    updateByNim(List, "2311110029");
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE BY NIM ---" << endl;
    printList(List);
    
    return 0;
}
```

penjelasan singkat guided 3
File main.cpp berisi program utama untuk menguji fungsi Singly Linked List. Program diawali dengan membuat list kosong, kemudian mengalokasikan lima node berisi data mahasiswa dan memasukkannya ke dalam list menggunakan insertFirst(), insertLast(), dan insertAfter(). Selanjutnya, program menampilkan isi list beserta jumlah node, lalu melakukan pembaruan data menggunakan updateFirst(), updateLast(), updateAfter(), dan updateByNim(). Setiap perubahan ditampilkan kembali untuk melihat hasil pembaruan data mahasiswa.

## Unguided

### 1. Header

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;


typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int sumInfo(List L);

#endif
```

### 2. Singlylist.cpp

```C++
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

address findElm(List L, infotype x) {
    address bantu = L.First;
    while (bantu != Nil) {
        if (bantu->info == x) {
            return bantu;
        }
        bantu = bantu->next;
    }
    return Nil;
}

int sumInfo(List L) {
    int total = 0;
    address bantu = L.First;
    while (bantu != Nil) {
        total += bantu->info;
        bantu = bantu->next;
    }
    return total;
}
```

### 2. Singlylist.cpp
```C++
#include <iostream>
#include "Singlylist.h"
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    address cari = findElm(L, 8);
    if (cari != Nil) {
        cout << "8 ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah " << sumInfo(L) << endl;

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Isanmaulana/109082500093/blob/main/laprak5/SS%20OUTPUT/SS1.png)

penjelasan unguided 1
1. File Header (Singlylist.h) mendeklarasikan struktur ElmList yang memiliki atribut info bertipe infotype (int) untuk menyimpan data dan next bertipe address sebagai pointer ke node berikutnya. File ini juga mendeklarasikan struktur List dengan atribut First sebagai penunjuk ke node pertama. Selain itu, terdapat deklarasi fungsi createList(), alokasi(), dealokasi(), printInfo(), insertFirst(), findElm(), dan sumInfo() untuk mengelola, mencari, serta menjumlahkan data dalam Singly Linked List. Penggunaan #ifndef, #define, dan #endif bertujuan mencegah header dimasukkan berulang kali, sedangkan #define Nil NULL mendefinisikan Nil sebagai pointer kosong.
2. File Kode Utama (Singlylist.cpp) mengimplementasikan fungsi-fungsi yang telah dideklarasikan pada file header. Fungsi createList() digunakan untuk membuat list kosong dengan mengisi First dengan Nil, alokasi() untuk membuat node baru dan mengisi nilai info, sedangkan dealokasi() berfungsi membebaskan memori node. Fungsi printInfo() digunakan untuk menampilkan seluruh data dari node pertama sampai terakhir, dan insertFirst() untuk menambahkan node di awal list. Selain itu, fungsi findElm() digunakan untuk mencari data tertentu dalam list dan mengembalikan alamat node yang ditemukan (atau Nil jika tidak ada), sedangkan sumInfo() digunakan untuk menjumlahkan seluruh nilai info pada setiap node dan mengembalikan hasil penjumlahannya.
3. File Main (main.cpp) berfungsi sebagai bagian utama program yang menjalankan fungsi-fungsi Singly Linked List. Program membuat list kosong melalui createList(), kemudian membuat lima node dengan nilai 2, 0, 8, 12, dan 9 menggunakan fungsi alokasi(). Setiap node dimasukkan ke awal list menggunakan insertFirst(), sehingga urutan data menjadi 9 12 8 0 2. Selanjutnya, fungsi printInfo() dipanggil untuk menampilkan seluruh data, findElm() untuk mencari nilai 8 lalu menampilkan pesan “8 ditemukan dalam list”, dan sumInfo() untuk menjumlahkan seluruh nilai dalam list yang kemudian ditampilkan dengan cout. Hasil penjumlahannya adalah 31, sebelum program berakhir dengan return 0.


## Kesimpulan
Di minggu kali ini saya belajar mengenai pembuatan dan pengolahan data pada Singly Linked List menggunakan bahasa pemrograman C++. Saya mempelajari cara membuat ADT yang terdiri dari struktur node dan list, serta menyimpan data pada node yang saling terhubung melalui pointer. Selain itu, saya juga memahami penggunaan fungsi seperti createList(), alokasi(), dealokasi(), insertFirst(), printInfo(), findElm(), dan sumInfo() untuk membantu proses penambahan, penampilan, pencarian, dan penjumlahan data. Dari praktikum ini, saya menjadi lebih memahami cara menelusuri node menggunakan pointer serta bagaimana data dalam linked list dapat ditambahkan di awal list, dicari, dan dihitung totalnya tanpa harus menggunakan array.

...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...