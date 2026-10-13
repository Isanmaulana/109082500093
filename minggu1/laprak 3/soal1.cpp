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