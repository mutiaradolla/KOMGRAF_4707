// Mutiara Dolla Meitantya | A11.2021.13745 | HW2
#include <iostream>
#include <limits> // Digunakan untuk membersihkan buffer input

using namespace std;

// Fungsi untuk menampilkan matriks
void tampilkanMatriks(int matriks[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriks[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk penjumlahan dua matriks
void penjumlahanMatriks(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Fungsi untuk pengurangan dua matriks
void penguranganMatriks(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Fungsi untuk perkalian skalar pada matriks
void perkalianSkalar(int skalar, int matriks[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = skalar * matriks[i][j];
        }
    }
}

// Fungsi untuk perkalian dua matriks
void perkalianMatriks(int A[2][2], int B[2][2], int hasil[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriks1[2][2], matriks2[2][2], hasil[2][2], hasilSkalar[2][2];
    int skalar;
    int pilihan;
    char lanjut;

    do {
        cout << "Pilih operasi yang ingin Anda lakukan:\n";
        cout << "1. Penjumlahan Matriks\n";
        cout << "2. Pengurangan Matriks\n";
        cout << "3. Perkalian Skalar\n";
        cout << "4. Perkalian Matriks\n";
        cout << "Masukkan nomor operasi (1/2/3/4): ";

        // Menangani input yang tidak valid
        while (!(cin >> pilihan) || pilihan < 1 || pilihan > 4) {
            cin.clear(); // Mengembalikan status input stream ke normal
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Menghapus karakter sampai akhir baris
            cout << "Inputan salah. Masukkan nomor operasi yang valid (1/2/3/4): ";
        }

        cout << "Masukkan elemen matriks pertama: \n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> matriks1[i][j];
            }
        }

        cout << "Masukkan elemen matriks kedua: \n";
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> matriks2[i][j];
            }
        }

        if (pilihan == 1) {
            cout << "Hasil penjumlahan matriks:\n";
            penjumlahanMatriks(matriks1, matriks2, hasil);
            tampilkanMatriks(hasil);
        } else if (pilihan == 2) {
            cout << "Hasil pengurangan matriks:\n";
            penguranganMatriks(matriks1, matriks2, hasil);
            tampilkanMatriks(hasil);
        } else if (pilihan == 3) {
            cout << "Masukkan skalar: ";

            // Menangani input skalar yang tidak valid
            while (!(cin >> skalar)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Inputan salah. Masukkan skalar yang valid: ";
            }

            cout << "Hasil perkalian skalar matriks pertama:\n";
            perkalianSkalar(skalar, matriks1, hasilSkalar);
            tampilkanMatriks(hasilSkalar);
            cout << "Hasil perkalian skalar matriks kedua:\n";
            perkalianSkalar(skalar, matriks2, hasil);
            tampilkanMatriks(hasil);
        } else if (pilihan == 4) {
            cout << "Hasil perkalian dua matriks:\n";
            perkalianMatriks(matriks1, matriks2, hasil);
            tampilkanMatriks(hasil);
        }

        cout << "Apakah Anda ingin melakukan operasi matriks lagi? (Y/N): ";
        cin >> lanjut;
    } while (lanjut == 'Y' || lanjut == 'y');

    cout << "Baiklaaahh." << endl;

    return 0;
}
