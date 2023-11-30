#include <iostream>
#include <vector>
#include <cmath>

// Fungsi untuk mencetak matriks
void cetak_matriks(const std::vector<std::vector<double>>& matriks) {
    for (const auto& baris : matriks) {
        for (const auto& elemen : baris) {
            std::cout << elemen << ' ';
        }
        std::cout << '\n';
    }
}

// Fungsi untuk mencetak titik koordinat
void cetak_titik(const std::vector<double>& titik) {
    for (const auto& elemen : titik) {
        std::cout << elemen << '\n';
    }
}

// Fungsi untuk melakukan translasi
std::vector<double> translasi(const std::vector<double>& titik, double tx, double ty) {
    std::vector<std::vector<double>> matriks_translasi = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    cetak_matriks(matriks_translasi);

    // Hasil Translasi
    std::cout << "Hasil Translasi:\n";
    std::vector<double> hasil_translasi = {titik[0] + tx, titik[1] + ty, 1};
    cetak_titik(hasil_translasi);

    return hasil_translasi;
}

// Fungsi untuk melakukan skala
std::vector<double> skala(const std::vector<double>& titik, double Sx, double Sy) {
    std::vector<std::vector<double>> matriks_skala = {{Sx, 0, 0}, {0, Sy, 0}, {0, 0, 1}};
    cetak_matriks(matriks_skala);

    // Hasil Skala
    std::cout << "Hasil Skala:\n";
    std::vector<double> hasil_skala = {titik[0] * Sx, titik[1] * Sy, 1};
    cetak_titik(hasil_skala);

    return hasil_skala;
}

// Fungsi untuk melakukan rotasi
std::vector<double> rotasi(const std::vector<double>& titik, double sudut) {
    double radian = sudut * M_PI / 180.0;
    double cos_theta = cos(radian);
    double sin_theta = sin(radian);
    std::vector<std::vector<double>> matriks_rotasi = {{cos_theta, -sin_theta, 0}, {sin_theta, cos_theta, 0}, {0, 0, 1}};
    cetak_matriks(matriks_rotasi);

    // Hasil Rotasi
    std::cout << "Hasil Rotasi:\n";
    std::vector<double> hasil_rotasi = {titik[0] * cos_theta - titik[1] * sin_theta, titik[0] * sin_theta + titik[1] * cos_theta, 1};
    cetak_titik(hasil_rotasi);

    return hasil_rotasi;
}

// Fungsi untuk melakukan mirror
std::vector<double> mirror(const std::vector<double>& titik, bool sumbu_x) {
    std::vector<std::vector<double>> matriks_mirror;
    if (sumbu_x) {
        matriks_mirror = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}};
    } else {
        matriks_mirror = {{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    }
    cetak_matriks(matriks_mirror);

    // Hasil Mirror
    std::cout << "Hasil Mirror:\n";
    std::vector<double> hasil_mirror = sumbu_x ? std::vector<double>{titik[0], -titik[1], 1} : std::vector<double>{-titik[0], titik[1], 1};
    cetak_titik(hasil_mirror);

    return hasil_mirror;
}

// Fungsi untuk melakukan composite transformation
std::vector<double> composite(const std::vector<double>& titik, double tx, double ty, double Sx, double Sy, double sudut) {
    std::vector<double> hasil_translasi = translasi(titik, tx, ty);
    std::vector<double> hasil_skala = skala(hasil_translasi, Sx, Sy);
    std::vector<double> hasil_rotasi = rotasi(hasil_skala, sudut);

    // Hasil Composite Transformation
    std::cout << "Hasil Composite Transformation:\n";
    cetak_titik(hasil_rotasi);

    return hasil_rotasi;
}

int main() {
    double x, y;
    std::cout << "Masukkan koordinat titik (x, y): ";
    std::cin >> x >> y;

    std::vector<double> titik = {x, y, 1};

    int pilihan;
    std::cout << "Pilih transformasi:\n";
    std::cout << "1. Translasi\n";
    std::cout << "2. Skala\n";
    std::cout << "3. Rotasi\n";
    std::cout << "4. Mirror\n";
    std::cout << "5. Composite\n";
    std::cout << "Masukkan nomor transformasi: ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1: {
            double tx, ty;
            std::cout << "Masukkan faktor translasi X: ";
            std::cin >> tx;
            std::cout << "Masukkan faktor translasi Y: ";
            std::cin >> ty;
            translasi(titik, tx, ty);
            break;
        }
        case 2: {
            double Sx, Sy;
            std::cout << "Masukkan faktor skala X: ";
            std::cin >> Sx;
            std::cout << "Masukkan faktor skala Y: ";
            std::cin >> Sy;
            skala(titik, Sx, Sy);
            break;
        }
        case 3: {
            double sudut;
            std::cout << "Masukkan sudut rotasi (derajat): ";
            std::cin >> sudut;
            rotasi(titik, sudut);
            break;
        }
        case 4: {
            int pilihan_mirror;
            std::cout << "Pilih sumbu mirror:\n";
            std::cout << "1. Sumbu X\n";
            std::cout << "2. Sumbu Y\n";
            std::cout << "Masukkan nomor sumbu: ";
            std::cin >> pilihan_mirror;
            mirror(titik, pilihan_mirror == 1);
            break;
        }
        case 5: {
            double tx, ty, Sx, Sy, sudut;
            std::cout << "Masukkan faktor translasi X: ";
            std::cin >> tx;
            std::cout << "Masukkan faktor translasi Y: ";
            std::cin >> ty;
            std::cout << "Masukkan faktor skala X: ";
            std::cin >> Sx;
            std::cout << "Masukkan faktor skala Y: ";
            std::cin >> Sy;
            std::cout << "Masukkan sudut rotasi (derajat): ";
            std::cin >> sudut;

            composite(titik, tx, ty, Sx, Sy, sudut);
            break;
        }
        default:
            std::cout << "Pilihan tidak valid.\n";
            break;
    }

    return 0;
}
