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