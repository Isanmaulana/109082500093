# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ichsan Maulana Muhammad - 109082500093</p>

## Dasar Teori

Queue merupakan struktur data yang menerapkan prinsip FIFO (First In First Out), di mana elemen yang paling awal dimasukkan akan menjadi elemen yang paling awal dikeluarkan. Berbeda dengan Stack yang hanya memiliki satu ujung aktif, Queue memiliki dua ujung yang masing-masing memiliki fungsi berbeda: ujung depan (head) digunakan untuk proses penghapusan data, sedangkan ujung belakang (tail) digunakan untuk proses penambahan data.Operasi dasar yang harus dimiliki oleh sebuah Queue meliputi:
1. createQueue : menginisialisasi Queue dalam keadaan kosong
2. isEmptyQueue : memeriksa apakah Queue dalam keadaan kosong
3. isFullQueue : memeriksa apakah kapasitas Queue sudah penuh
4. enqueue : menambahkan sebuah elemen baru melalui tail
5. dequeue : mengambil sekaligus menghapus elemen yang berada di posisi head
6. printInfo : menampilkan seluruh isi Queue beserta posisi head dan tail saat itu

## Guided

### 1. Header

```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;
const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif
```

penjelasan singkat guided 1
File queue.h berisi deklarasi struktur data dan fungsi-fungsi untuk mengelola Queue berbasis Array. Struktur queue memiliki array nama bertipe string dengan kapasitas maksimal 5 elemen, serta variabel head dan tail yang berfungsi menandai posisi elemen paling depan dan paling belakang. Header ini juga mendeklarasikan fungsi untuk mengecek kondisi Queue (isFull dan isEmpty), membuat Queue kosong (CreateQueue), menambahkan data (enQueue), menghapus data (deQueue), dan menampilkan seluruh isi Queue (viewQueue).

### 2. Kode Utama

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikeluarin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
```

penjelasan singkat guided 2
File queue.cpp berisi implementasi fungsi-fungsi yang telah dideklarasikan di queue.h. Saat ini kode yang aktif menggunakan Implementasi 1 (head diam, tail bergerak). Pada implementasi ini, fungsi isEmpty mengecek apakah head dan tail bernilai -1, sedangkan isFull mengecek apakah tail sudah mencapai indeks terakhir. Fungsi CreateQueue menginisialisasi Queue dengan mengatur head dan tail menjadi -1. Fungsi enQueue menambahkan data ke posisi tail, dan jika Queue masih kosong maka head dan tail diatur ke 0. Fungsi deQueue menghapus data di posisi head lalu menggeser seluruh elemen ke kiri agar head tetap di indeks 0. Sementara itu, fungsi viewQueue menampilkan seluruh isi Queue dari posisi head sampai tail.

### 3. Main

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

penjelasan singkat guided 3
File main.cpp berisi program utama untuk menguji ADT Queue. Pertama-tama dibuat sebuah objek Queue bernama Q, lalu diinisialisasi menggunakan CreateQueue. Setelah itu dilakukan beberapa kali enQueue untuk memasukkan nama-nama ke dalam Queue. Selanjutnya isi Queue ditampilkan menggunakan viewQueue. Setelah itu dilakukan beberapa kali deQueue untuk menghapus data dari depan Queue, kemudian isi Queue ditampilkan kembali untuk melihat hasil setelah proses penghapusan.

## Unguided

### 1. Header Queue

```C++
#ifndef QUEUE_H
#define QUEUE_H

const int MAX = 5;

typedef int infotype;

struct Queue {
    infotype info[MAX];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```
### 2. Kode Utama Queue
### Queue1.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -999;

    int x = Q.info[0];

    // geser ke kiri
    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;

    if (Q.tail < 0) {
        Q.head = -1;
        Q.tail = -1;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = 0; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### Queue2.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == MAX - 1);
}

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -999;

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head++;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        for (int i = Q.head; i <= Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
        cout << endl;
    }
}
```

### Queue3.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, int x) {
    if (isFullQueue(Q)) return;

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }
    Q.info[Q.tail] = x;
}

int dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) return -999;

    int x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }
    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
    } else {
        int i = Q.head;
        while (true) {
            cout << Q.info[i] << " ";
            if (i == Q.tail) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}
```

### Main Queue1 dan 2
```C++
#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------" << endl;
    cout << "H - T | Queue info" << endl;
    cout << "----------------" << endl;

    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    return 0;
}
```

### Main Queue3
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;

    Queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;

    printInfo(Q);
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    enqueue(Q, 4);
    printInfo(Q);
    enqueue(Q, 6);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q, 8);
    printInfo(Q);
    enqueue(Q, 9);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);

    return 0;
}
```
### Output Unguided 1 :
##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

### Output Unguided 2 :

##### Output 2

![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

### Output Unguided 3 :

##### Output 3

![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan:
1. queue.h
Queue.h berisi deklarasi struktur data dan fungsi-fungsi untuk mengelola Queue menggunakan Array. Struktur queue memiliki array info dengan kapasitas maksimal 5 elemen, serta variabel head dan tail untuk menandai posisi elemen pertama dan terakhir. Header ini juga mendeklarasikan fungsi untuk mengecek kondisi Queue (isEmpty dan isFull), membuat Queue kosong (CreateQueue), menambahkan data (enqueue), menghapus data (dequeue), dan menampilkan isi Queue (printInfo).

2. Queue1.cpp (Implementasi 1: Head Diam, Tail Bergerak)
File ini merupakan implementasi Queue dengan mekanisme head diam dan tail bergerak. Pada implementasi ini, setiap kali dilakukan dequeue, seluruh elemen digeser ke kiri sehingga posisi head selalu tetap di indeks 0. Fungsi enqueue menambahkan data di posisi tail, sedangkan printInfo menampilkan seluruh elemen dari indeks 0 sampai tail.

3. Queue2.cpp (Implementasi 2: Head Bergerak, Tail Bergerak)
File ini mengimplementasikan Queue dengan mekanisme head dan tail sama-sama bergerak. Saat dequeue dilakukan, nilai head digeser maju tanpa menggeser elemen. Akibatnya, ruang di bagian depan array yang sudah dikosongkan tidak dapat digunakan kembali sampai Queue benar-benar kosong.

4. Queue3.cpp (Implementasi 3: Head dan Tail Berputar)
File ini merupakan implementasi Circular Queue. Posisi head dan tail dihitung secara modular (% MAX) sehingga ketika mencapai indeks terakhir, indeks berikutnya akan kembali ke awal array. Pendekatan ini memungkinkan ruang yang sudah dikosongkan di depan dapat digunakan kembali.

5. main.cpp (Main Queue Implementasi 1 dan 2)
File main.cpp ini digunakan untuk menguji Implementasi 1 dan Implementasi 2. Program membuat Queue, melakukan beberapa operasi enqueue dan dequeue, lalu menampilkan isi Queue setelah setiap operasi untuk melihat perubahan posisi head dan tail.

6. main.cpp (Main Queue Implementasi 3)
File main.cpp ini khusus digunakan untuk menguji Implementasi 3 (Circular). Program melakukan lebih banyak operasi enqueue dan dequeue agar terlihat proses perputaran head dan tail ketika ruang di depan array digunakan kembali setelah beberapa data dihapus.

## Kesimpulan
Pada praktikum ini saya mempelajari struktur data Queue dalam C++ yang bekerja dengan prinsip FIFO (First In, First Out). Operasi dasarnya meliputi enqueue() untuk menambah data, dequeue() untuk menghapus data, printInfo() untuk menampilkan isi Queue, serta isEmptyQueue() dan isFullQueue() untuk memeriksa kondisi kosong atau penuh.

Implementasi dengan Array terbagi menjadi tiga jenis:

1. Head Diam, Tail Bergerak: elemen digeser ke kiri setiap dequeue, sederhana tetapi kurang efisien.
2. Head Bergerak, Tail Bergerak: lebih cepat, tetapi ruang di depan tidak bisa dipakai ulang.
3. Circular Queue: memakai modulo (% MAX) sehingga ruang kosong dapat dimanfaatkan kembali.

Sementara itu, Linked List memungkinkan penambahan dan penghapusan data secara dinamis tanpa batas kapasitas tetap. Dengan demikian, Array cocok untuk data terbatas, Circular Queue lebih efisien, dan Linked List lebih fleksibel.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...