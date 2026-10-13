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

### 1. Header Buku

```C++
#ifndef BUKU_H
#define BUKU_H
#include <iostream>

using namespace std;

struct buku{
    string judul;
    int halaman;
    string penulis;
};

void editIsi(string judul, int halaman, string penulis, buku &buku);
void tampilkanIsiBuku(buku buku);
bool checkPenulis(buku buku);

#endif
```

Program tersebut digunakan sebagai header untuk mendeklarasikan struktur data dan fungsi yang akan digunakan dalam pengelolaan data buku. Struktur buku memiliki tiga atribut, yaitu judul bertipe string, halaman bertipe int, dan penulis bertipe string. Header ini juga mendeklarasikan tiga fungsi, yaitu editIsi() untuk mengisi data buku, tampilkanIsiBuku() untuk menampilkan informasi buku, dan checkPenulis() untuk memeriksa apakah nama penulis kosong. Penggunaan #ifndef, #define, dan #endif bertujuan untuk mencegah header diproses berulang kali.

### 2. Kode

```C++
#include "buku.h"

void editIsi(string judul, int halaman, string penulis, buku &buku){
    buku.judul = judul;
    buku.halaman = halaman;
    buku.penulis = penulis;
}

void tampilkanIsiBuku(buku buku)
{
    cout << "Judul Buku :" << buku.judul << endl;
    cout << "Halaman Buku :" << buku.halaman << endl;
    cout << "Penulis Buku :" << buku.penulis << endl;
}

bool checkPenulis(buku buku){
    return buku.penulis == "";
}
```

Program tersebut digunakan untuk mengimplementasikan tiga fungsi yang telah dideklarasikan pada header buku.h. Fungsi editIsi() digunakan untuk mengisi atau mengubah data judul, jumlah halaman, dan penulis melalui parameter referensi buku &buku, sehingga perubahan dilakukan pada objek buku asli. Fungsi tampilkanIsiBuku() digunakan untuk menampilkan informasi judul, jumlah halaman, dan nama penulis buku. Sementara itu, fungsi checkPenulis() mengembalikan nilai true jika nama penulis kosong dan false jika nama penulis terisi.

### 3. Main

```C++
#include <iostream>
#include "buku.h"
using namespace std;

int main(){
    buku novel;
    string judul, penulis;
    int halaman;

    cout << "Masuk nama judul buku: ";
    cin >> judul;
    cout << "Masuk halaman buku: ";
    cin >> halaman;
    cout << "Masuk nama penulis buku: ";
    cin >> penulis;

    editIsi(judul, halaman, penulis, novel);
    tampilkanIsiBuku(novel);

    cout << checkPenulis(novel);
    return 0;
}
```

Program tersebut digunakan sebagai program utama untuk menjalankan pengelolaan data buku. Program diawali dengan membuat objek novel bertipe buku, kemudian meminta pengguna memasukkan judul buku, jumlah halaman, dan nama penulis. Data yang dimasukkan selanjutnya dikirim ke fungsi editIsi() untuk disimpan ke dalam objek novel. Setelah itu, fungsi tampilkanIsiBuku() dipanggil untuk menampilkan informasi buku, sedangkan fungsi checkPenulis() digunakan untuk memeriksa apakah nama penulis kosong. Program diakhiri dengan return 0 sebagai tanda bahwa program selesai dijalankan.

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array
dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI
dengan rumus 0.3*uts+0.4*uas+0.3*tugas.

```C++
#include <iostream>
#include <string>
using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, akhir;
};

float hitung_nilai(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    mahasiswa mhs;

    cout << "Masukan Nama: ";
    getline(cin, mhs.nama);

    cout << "Masukan NIM: ";
    getline(cin, mhs.nim);

    cout << "Masukan Nilai UTS: ";
    cin >> mhs.uts;

    cout << "Masukan Nilai UAS: ";
    cin >> mhs.uas;

    cout << "Masukan Nilai Tugas: ";
    cin >> mhs.tugas;

    mhs.akhir = hitung_nilai(mhs.uts, mhs.uas, mhs.tugas);

    cout << "Nilai Akhir: " << mhs.akhir << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Isanmaulana/109082500093/blob/main/laprak%203/SS%20OUTPUT/ss1.png)


##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/Isanmaulana/109082500093/blob/main/laprak%203/SS%20OUTPUT/ss2.png)

penjelasan unguided 1
Program tersebut digunakan untuk menginput, menyimpan, dan menghitung nilai akhir mahasiswa menggunakan struktur mahasiswa. Variabel mhs digunakan untuk menyimpan data mahasiswa berupa nama, NIM, nilai UTS, UAS, dan tugas. Fungsi hitung_nilai() digunakan untuk menghitung nilai akhir berdasarkan rumus 0.3 × UTS + 0.4 × UAS + 0.3 × tugas. Terakhir, program menampilkan nilai akhir mahasiswa berdasarkan hasil perhitungan tersebut.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”:

Header Pelajaran
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif
```
pelajaran cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```
Main cpp
```C++
#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}
```
### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/Isanmaulana/109082500093/blob/main/laprak%203/SS%20OUTPUT/ss3.png)

penjelasan unguided 2
1. File Header (pelajaran.h) mendeklarasikan struktur pelajaran yang memiliki atribut namaMapel dan kodeMapel bertipe string. File ini juga mendeklarasikan fungsi create_pelajaran() untuk membuat data pelajaran dan prosedur tampil_pelajaran() untuk menampilkan data pelajaran. Penggunaan #ifndef, #define, dan #endif bertujuan mencegah header dimasukkan berulang kali.
2. File Kode Utama (pelajaran.cpp) mengimplementasikan fungsi yang telah dideklarasikan pada file header. Fungsi create_pelajaran() menerima parameter namapel dan kodepel, mengisikannya ke atribut namaMapel dan kodeMapel, kemudian mengembalikan data bertipe pelajaran. Sementara itu, prosedur tampil_pelajaran() menampilkan nama dan kode pelajaran menggunakan cout.
3. File Main (main.cpp) berfungsi sebagai bagian utama program yang menjalankan fungsi-fungsi yang telah dibuat. Program menginisialisasi variabel namapel dengan nilai "Struktur Data" dan kodepel dengan nilai "STD". Selanjutnya, fungsi create_pelajaran() dipanggil untuk membuat data pelajaran dan hasilnya disimpan ke variabel pel. Prosedur tampil_pelajaran() kemudian dipanggil untuk menampilkan data tersebut ke layar sebelum program berakhir dengan return 0.

### 3. Buatlah program dengan ketentuan :
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu

```C++
#include <iostream>
using namespace std;

void tampil_array(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukar_array(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };

    int *pA = &A[0][0];
    int *pB = &B[0][0];

    cout << "Array A sebelum ditukar:" << endl;
    tampil_array(A);

    cout << "\nArray B sebelum ditukar:" << endl;
    tampil_array(B);

    int baris = 1;
    int kolom = 1;

    tukar_array(&A[baris][kolom], &B[baris][kolom]);

    cout << "\nArray A setelah ditukar:" << endl;
    tampil_array(A);

    cout << "\nArray B setelah ditukar:" << endl;
    tampil_array(B);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/Isanmaulana/109082500093/blob/main/laprak%203/SS%20OUTPUT/ss4.png)

penjelasan unguided 3
Program tersebut digunakan untuk membuat dan menampilkan dua array integer berukuran 3×3 serta menukar nilai elemen pada posisi tertentu menggunakan pointer. Array A dan B digunakan untuk menyimpan data integer, sedangkan pointer pA dan pB digunakan untuk menunjuk ke elemen pertama masing-masing array. Fungsi tampil_array() digunakan untuk menampilkan seluruh isi array, sedangkan fungsi tukar_array() digunakan untuk menukar nilai dua elemen menggunakan pointer. Terakhir, program menukar elemen pada baris kedua dan kolom kedua dari kedua array, kemudian menampilkan hasilnya.

## Kesimpulan
Praktikum ini memberikan pemahaman tentang penggunaan berbagai konsep dalam C++, seperti struct, array, fungsi, pointer, dan header. Konsep tersebut diterapkan untuk membuat program pengolahan data mahasiswa, membentuk ADT pelajaran, serta menukar nilai elemen pada array dua dimensi. Melalui latihan ini, dapat dipahami bahwa pembagian program ke dalam beberapa fungsi dan file membantu membuat kode lebih rapi, terorganisir, dan mudah dikembangkan.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...