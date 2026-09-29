# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Ichsan Maulana Muhammad - 109082500093</p>

## Dasar Teori

A. Dasar Bahasa C++
C++ merupakan bahasa pemrograman yang dapat digunakan untuk membuat berbagai jenis program. C++ mendukung pemrograman prosedural dan berorientasi objek serta memiliki berbagai konsep dasar seperti variabel, tipe data, input-output, operator, percabangan, fungsi, dan perulangan.

1. Variabel dan Tipe Data
Variabel merupakan tempat yang digunakan untuk menyimpan data dalam suatu program. Setiap variabel memiliki tipe data yang menentukan jenis nilai yang dapat disimpan. Beberapa tipe data dasar pada C++ yaitu int untuk bilangan bulat, float dan double untuk bilangan desimal, char untuk karakter, serta bool untuk nilai benar atau salah.

2. Input dan Output
Input dan output digunakan untuk menerima data dari pengguna dan menampilkan hasil pemrosesan program. Pada C++, cin digunakan untuk menerima input dari pengguna, sedangkan cout digunakan untuk menampilkan output ke layar. Fungsi input dan output tersebut dapat digunakan dengan library iostream.

3. Operator
Operator merupakan simbol yang digunakan untuk melakukan operasi terhadap data atau variabel. Pada C++ terdapat beberapa jenis operator, seperti operator aritmatika, operator perbandingan, dan operator logika. Operator aritmatika digunakan untuk melakukan perhitungan, sedangkan operator perbandingan dan logika digunakan dalam proses pengambilan keputusan.

4. Percabangan
Percabangan digunakan untuk menjalankan perintah berdasarkan kondisi tertentu. Pada C++, percabangan dapat menggunakan if, if-else, dan switch. Dengan menggunakan percabangan, program dapat menjalankan perintah yang berbeda sesuai dengan kondisi yang diberikan.

5. Perulangan
Perulangan digunakan untuk menjalankan suatu perintah secara berulang selama kondisi tertentu terpenuhi. C++ menyediakan beberapa jenis perulangan, yaitu for, while, dan do-while. Penggunaan perulangan dapat membuat program lebih sederhana karena tidak perlu menuliskan perintah yang sama berkali-kali.

6. Fungsi
Fungsi merupakan sekumpulan perintah yang dibuat untuk melakukan tugas tertentu dan dapat dipanggil kembali ketika diperlukan. Penggunaan fungsi dapat membantu membuat program menjadi lebih terstruktur dan memudahkan proses pengembangan serta pemeliharaan program.

7. Array
Array merupakan struktur data yang digunakan untuk menyimpan beberapa data dengan tipe yang sama dalam satu variabel. Setiap data dalam array memiliki indeks yang digunakan untuk mengakses elemen tertentu. Array dapat digunakan untuk mengelola kumpulan data secara lebih terorganisasi.

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian
memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cin >> a >> b;

    cout << "Penjumlahan = " << a + b << endl;
    cout << "Pengurangan = " << a - b << endl;
    cout << "Perkalian = " << a * b << endl;
    cout << "Pembagian = " << a / b << endl;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss2.png)

Program ini dirancang untuk menerima dua buah masukan angka pecahan (floating-point) dari pengguna. Variabel dideklarasikan menggunakan tipe data float agar dapat menyimpan nilai desimal. Setelah kedua nilai dimasukkan, program akan menghitung dan menampilkan hasil penjumlahan, pengurangan, perkalian, serta pembagian dari kedua bilangan tersebut. Pada operasi pembagian, digunakan pengecekan kondisi if (b != 0) untuk memastikan bilangan kedua tidak bernilai nol sehingga pembagian dapat dilakukan dengan aman.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai
angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat
positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main() {
    int angka;

    cin >> angka;

    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan",
        "sepuluh", "sebelas"
    };

    if (angka <= 11) {
        cout << satuan[angka];
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas";
    }
    else if (angka < 100) {
        cout << satuan[angka / 10] << " puluh";
        
        if (angka % 10 != 0) {
            cout << " " << satuan[angka % 10];
        }
    }
    else {
        cout << "seratus";
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss3.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss4.png)

Program ini dirancang untuk menerima masukan berupa bilangan bulat positif dengan rentang nilai 0 sampai 100 dari pengguna. Program kemudian mengolah nilai tersebut menggunakan percabangan untuk menentukan bentuk tulisan yang sesuai dengan angka yang dimasukkan. Untuk bilangan puluhan, program memisahkan nilai puluhan dan satuannya sehingga dapat menghasilkan tulisan seperti “tujuh puluh sembilan” untuk input 79. Dengan demikian, output yang dihasilkan merupakan bentuk tulisan dari angka yang diberikan oleh pengguna.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        
        for (int j = n; j > i; j--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss5.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/Isanmaulana/109082500093/blob/main/minggu1/SS%20OUTPUT/ss6.png)

Program ini dirancang untuk menerima sebuah bilangan sebagai masukan dan menghasilkan pola angka berbentuk mirror sesuai dengan nilai yang diberikan. Program menggunakan perulangan untuk mengatur jumlah baris serta jumlah angka yang ditampilkan pada setiap baris. Pada setiap baris, jumlah angka akan semakin berkurang hingga menghasilkan satu simbol * pada baris terakhir. Selain itu, pengaturan spasi digunakan agar pola yang dihasilkan sesuai dengan bentuk mirror pada contoh soal.

## Kesimpulan
C++ memiliki beberapa konsep dasar seperti input dan output, variabel, operator, percabangan, fungsi, dan perulangan. Dengan praktikum ini, konsep tersebut dapat diterapkan untuk membuat program sederhana, melakukan operasi aritmatika, mengubah angka menjadi tulisan, serta membuat pola menggunakan perulangan. Melalui penerapan konsep-konsep tersebut, dapat dipahami bagaimana logika pemrograman digunakan untuk mengolah masukan menjadi keluaran sesuai dengan kebutuhan program.
...

## Referensi

[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN.
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...