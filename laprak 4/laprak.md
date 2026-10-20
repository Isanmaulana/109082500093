# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ichsan Maulana Muhammad - 109082500093</p>

## Dasar Teori

A. Dasar Bahasa C++
C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program. C++ mendukung pemrograman prosedural dan berorientasi objek serta memiliki berbagai konsep dasar seperti variabel, tipe data, input-output, operator, percabangan, fungsi, dan perulangan.

1. Variabel dan Tipe Data merupakan tempat yang digunakan untuk menyimpan data dalam suatu program. Setiap variabel memiliki tipe data yang menentukan jenis nilai yang dapat disimpan. Beberapa tipe data dasar pada C++ yaitu int untuk bilangan bulat, float dan double untuk bilangan desimal, char untuk karakter, serta bool untuk nilai benar atau salah.

2. Input dan Output digunakan untuk menerima data dari pengguna dan menampilkan hasil pemrosesan program. Pada C++, cin digunakan untuk menerima input dari pengguna, sedangkan cout digunakan untuk menampilkan output ke layar. Fungsi input dan output tersebut dapat digunakan dengan library iostream.

3. Operator merupakan simbol yang digunakan untuk melakukan operasi terhadap data atau variabel. Pada C++ terdapat beberapa jenis operator, seperti operator aritmatika, operator perbandingan, dan operator logika. Operator aritmatika digunakan untuk melakukan perhitungan, sedangkan operator perbandingan dan logika digunakan dalam proses pengambilan keputusan.

4. Percabangan digunakan untuk menjalankan perintah berdasarkan kondisi tertentu. Pada C++, percabangan dapat menggunakan if, if-else, dan switch. Dengan menggunakan percabangan, program dapat menjalankan perintah yang berbeda sesuai dengan kondisi yang diberikan.

5. Perulangan digunakan untuk menjalankan suatu perintah secara berulang selama kondisi tertentu terpenuhi. C++ menyediakan beberapa jenis perulangan, yaitu for, while, dan do-while. Penggunaan perulangan dapat membuat program lebih sederhana karena tidak perlu menuliskan perintah yang sama berkali-kali.

6. Fungsi merupakan sekumpulan perintah yang dibuat untuk melakukan tugas tertentu dan dapat dipanggil kembali ketika diperlukan. Penggunaan fungsi dapat membantu membuat program menjadi lebih terstruktur dan memudahkan proses pengembangan serta pemeliharaan program.

7. Array merupakan struktur data yang digunakan untuk menyimpan beberapa data dengan tipe yang sama dalam satu variabel. Setiap data dalam array memiliki indeks yang digunakan untuk mengakses elemen tertentu. Array dapat digunakan untuk mengelola kumpulan data secara lebih terorganisasi.


## Guided

### 1. Header

```C++
#ifndef List_h
#define List_h
#define Nil nullptr

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

struct linkedList
{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi (string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);
#endif
```

penjelasan singkat guided 1
Header List.h berisi deklarasi struktur data dan fungsi untuk membuat Singly Linked List dengan data mahasiswa. Di dalamnya terdapat struktur mahasiswa untuk menyimpan nama, NIM, dan umur, serta struktur node yang menyimpan data mahasiswa dan pointer ke node berikutnya. Header ini juga mendeklarasikan fungsi untuk membuat list, menambah node, menghapus node, menampilkan data, dan menghitung jumlah node.

### 2. List.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List)
{
    if (List.first == Nil){
        return true;
    }else{
        return false;
    }
}

void createList(linkedList &List)
{
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &list, address nodeBaru)
{
    nodeBaru->next = list.first;
    list.first = nodeBaru;
}

void insertAfter(linkedList &list, address nodeBaru, address prev)
{
    if (prev != Nil)
    {
        nodeBaru->next = prev->next;
        prev->next = nodeBaru;
    }else{
        cout<< "Node sebelumnya tidak valid"<< endl;
    }
}

void insertLast(linkedList &list, address nodeBaru)
{
    if (isEmpty(list))
    {
        list.first = nodeBaru;
    }else
    {
        address nodeBantu = list.first;
        while(nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedList &list)
{
    address nodeHapus;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first;
        list.first = list.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }else
    {
        cout<<"List Kosong" << endl;
    }
}

void delLast(linkedList &list)
{
    address nodeHapus, nodePrev;
    if (isEmpty(list) == false)
    {
        nodeHapus = list.first; 
        if(nodeHapus->next == Nil)
        {
            list.first->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            while(nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }else
    {
        cout<<"List kosong"<< endl;
    }
}

void delAfter(linkedList &list, address nodeHapus, address nodePrev)
{
    if(isEmpty(list) == true)
    {
        cout<< "List kosong"<<endl;
    }else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }else
        {
            cout<<"Node sebelumnya (prev) tidak valid"<< endl;
        }
    }
}

void printList(linkedList list)
{
    if(isEmpty(list))
    {
        cout<< "List kosong." << endl;
    }else
    {
        address nodeBantu = list.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama: " << nodeBantu->isidata.nama << ", NIM: " << nodeBantu->isidata.nim << ", Usia: " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}


int nbList(linkedList list)
{
    int count = 0;
    address nodeBantu = list.first;
    while(nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

void deleteList(linkedList &list)
{
    address nodeBantu, nodeHapus;
    nodeBantu = list.first;

    while(nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    list.first = Nil;
    cout<< "List sudah terhapus"<< endl;
}
```

penjelasan singkat guided 2
File List.cpp berisi implementasi dari fungsi-fungsi yang dideklarasikan di List.h untuk mengelola Singly Linked List data mahasiswa. Di dalamnya terdapat fungsi untuk membuat list kosong, mengalokasikan node baru, menambah node di awal, tengah, dan akhir list, menghapus node, menampilkan seluruh data, serta menghitung dan menghapus seluruh node dalam list.

### 3. Main.cpp

```C++
#include "list.h"
using namespace std;

int main()
{
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "221110014", 21);
    nodeC = alokasi("Rizal", "231110029", 20);
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

    delFirst(List);
}
```

penjelasan singkat guided 3
File main.cpp berisi program utama yang menguji fungsi-fungsi Singly Linked List data mahasiswa. Di dalamnya dibuat list kosong, lima node mahasiswa dialokasikan, lalu disisipkan di awal, tengah, dan akhir list. Setelah itu isi list dan jumlah node ditampilkan, kemudian node pertama dihapus.

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

#endif
```

Singlylist.cpp

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
```

main.cpp

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

    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Isanmaulana/109082500093/blob/main/laprak%204/SS%20OUTPUT/ss1.png)

penjelasan unguided 1
1. Singlylist.h
File Singlylist.h berisi deklarasi struktur data dan fungsi untuk membuat Singly Linked List dengan data bertipe integer. Di dalamnya terdapat struktur ElmList yang menyimpan nilai dan pointer ke elemen berikutnya, serta struktur List yang menyimpan pointer ke elemen pertama. Header ini juga mendeklarasikan fungsi untuk membuat list, mengalokasikan dan mendealokasikan elemen, menambah elemen di awal, dan menampilkan isi list.
2. Singlylist.cpp
File Singlylist.cpp berisi implementasi dari fungsi-fungsi yang dideklarasikan di Singlylist.h. Fungsi createList mengisi First dengan Nil, alokasi membuat elemen baru dengan nilai tertentu, dealokasi menghapus elemen dari memori, insertFirst menyisipkan elemen di awal list, dan printInfo menampilkan seluruh isi list dari elemen pertama sampai terakhir.
3. main.cpp
File main.cpp berisi program utama untuk menguji Singly Linked List. Di dalamnya dibuat list kosong, lima elemen dengan nilai 2, 0, 8, 12, dan 9 dialokasikan lalu disisipkan satu per satu di awal list, kemudian isi list ditampilkan. Karena insertFirst menambah di depan, hasilnya berurutan terbalik dari urutan insert.

## Kesimpulan
Berdasarkan praktikum ini, Singly Linked List dapat diimplementasikan menggunakan tiga file, yaitu header (.h) untuk deklarasi struktur dan fungsi, file implementasi (.cpp) untuk isi fungsi, dan main.cpp untuk menjalankan program. Setiap elemen list menyimpan data dan pointer ke elemen berikutnya, sehingga data dapat ditambah tanpa memindahkan elemen lain. Pada program ini, fungsi insertFirst menambah elemen di awal list, sehingga data yang dimasukkan 2, 0, 8, 12, dan 9 tampil terbalik menjadi 9 12 8 0 2. Dengan memisahkan program ke dalam beberapa file, kode menjadi lebih rapi, terstruktur, dan mudah digunakan kembali.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...