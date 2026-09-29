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