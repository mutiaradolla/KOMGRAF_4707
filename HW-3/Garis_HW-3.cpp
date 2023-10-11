#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Fungsi untuk menghitung delta x, delta y, dan M
void hitungDeltaDanM(int xAwal, int yAwal, int xAkhir, int yAkhir, int &deltaX, int &deltaY, float &M) {
    deltaX = xAkhir - xAwal;
    deltaY = yAkhir - yAwal;
    M = static_cast<float>(deltaY) / static_cast<float>(deltaX);
}

// Fungsi untuk menampilkan informasi delta x, delta y, dan nilai M
void tampilkanInformasi(int deltaX, int deltaY, float M) {
    cout << "Delta X: " << deltaX << endl;
    cout << "Delta Y: " << deltaY << endl;
    cout << "Nilai M: " << M << endl;
}

// Fungsi untuk menampilkan nilai step berdasarkan perbandingan delta x dan delta y
void tampilkanStep(int deltaX, int deltaY) {
    int step;
    if (abs(deltaX) > abs(deltaY)) {
        step = abs(deltaX);
        cout << "Step: " << step << " (Delta X > Delta Y)" << endl;
    } else {
        step = abs(deltaY);
        cout << "Step: " << step << " (Delta X < Delta Y)" << endl;
    }
}

// Fungsi untuk menampilkan hasil perhitungan dalam bentuk tabel
void tampilkanTabel(int xAwal, int yAwal, int xAkhir, int yAkhir) {
    int deltaX, deltaY;
    float M;
    hitungDeltaDanM(xAwal, yAwal, xAkhir, yAkhir, deltaX, deltaY, M);

    tampilkanInformasi(deltaX, deltaY, M);
    tampilkanStep(deltaX, deltaY);

    int steps;
    if (abs(deltaX) > abs(deltaY)) {
        steps = abs(deltaX);
    } else {
        steps = abs(deltaY);
    }

    float Xp = static_cast<float>(xAwal);
    float Yp = static_cast<float>(yAwal);

    cout << "Rumus yang digunakan: " << endl;
    if (M < 1) {
        cout << "M < 1 (Rumus 1)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1;
            Yp += M;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    } else if (M == 1) {
        cout << "M = 1 (Rumus 2)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1;
            Yp += 1;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    } else {
        cout << "M > 1 (Rumus 3)" << endl;
        cout << left << setw(7) << "X Awal" << setw(7) << "Y Awal" << setw(7) << "Xp+1" << setw(7) << "Yp+1" << setw(14) << "(Xp+1, Yp+1)" << endl;
        for (int i = 0; i < steps; i++) {
            Xp += 1 / M;
            Yp += 1;
            cout << left << setw(7) << xAwal << setw(7) << yAwal << setw(7) << int(Xp + 0.5) << setw(7) << int(Yp + 0.5) << setw(15) << "(" << int(Xp + 0.5) << ", " << int(Yp + 0.5) << ")" << endl;
        }
    }
}

int main() {
    int xAwal = 4, yAwal = 1;
    int xAkhir = 8, yAkhir = 12;

    cout << "Titik A: (" << xAwal << ", " << yAwal << ")\n";
    cout << "Titik B: (" << xAkhir << ", " << yAkhir << ")\n";

    tampilkanTabel(xAwal, yAwal, xAkhir, yAkhir);

    return 0;
}
