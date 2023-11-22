#include <iostream>
#include <vector>

// Fungsi untuk mencetak matriks
void cetak_matriks(const std::vector<std::vector<double>>& matriks) {
    for (const auto& baris : matriks) {
        for (const auto& elemen : baris) {
            std::cout << elemen << ' ';
        }
        std::cout << '\n';
    }
}

// Fungsi untuk menghitung translasi matriks
std::vector<std::vector<double>> translasi_matriks(double tx, double ty) {
    return {{1, 0, tx},
            {0, 1, ty},
            {0, 0, 1}};
}

// Fungsi untuk melakukan translasi pada titik
std::vector<double> translasi_titik(const std::vector<double>& P, double tx, double ty) {
    return {{P[0] + tx},
            {P[1] + ty},
            {1}};
}

// Fungsi untuk menginput titik
std::vector<double> input_titik() {
    double x, y;
    std::cout << "Masukkan koordinat titik (x, y): ";
    std::cin >> x >> y;
    return {{x}, {y}, {1}};
}

int main() {
    double tx, ty;
    std::vector<double> P = input_titik();

    // Input translasi
    std::cout << "Masukkan translasi X: ";
    std::cin >> tx;
    std::cout << "Masukkan translasi Y: ";
    std::cin >> ty;

    // Mencetak matriks translasi
    std::cout << "Matriks Translasi:\n";
    cetak_matriks(translasi_matriks(tx, ty));

    // Mencetak matriks koordinat titik awal
    std::cout << "Matriks Koordinat Titik Awal:\n";
    cetak_matriks({P});

    // Melakukan translasi pada titik
    std::vector<double> P_translasi = translasi_titik(P, tx, ty);

    // Mencetak matriks koordinat titik akhir
    std::cout << "Matriks Koordinat Titik Akhir:\n";
    cetak_matriks({P_translasi});

    // Mencetak hasil translasi
    std::cout << "Hasil Translasi: (" << P_translasi[0] << ", " << P_translasi[1] << ")\n";

    return 0;
}