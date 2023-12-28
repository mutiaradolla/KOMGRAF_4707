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

// Fungsi untuk melakukan translasi 3D
std::vector<double> translasi_3d(const std::vector<double>& titik, double tx, double ty, double tz) {
    std::vector<std::vector<double>> matriks_translasi = {{1, 0, 0, tx},
                                                        {0, 1, 0, ty},
                                                        {0, 0, 1, tz},
                                                        {0, 0, 0, 1}};
    cetak_matriks(matriks_translasi);

    // Hasil Translasi 3D
    std::cout << "Hasil Translasi 3D:\n";
    std::vector<double> hasil_translasi_3d = {titik[0] + tx, titik[1] + ty, titik[2] + tz, 1};
    cetak_titik(hasil_translasi_3d);

    return hasil_translasi_3d;
}

// Fungsi untuk melakukan skala 3D
std::vector<double> skala_3d(const std::vector<double>& titik, double Sx, double Sy, double Sz) {
    std::vector<std::vector<double>> matriks_skala = {{Sx, 0, 0, 0},
                                                      {0, Sy, 0, 0},
                                                      {0, 0, Sz, 0},
                                                      {0, 0, 0, 1}};
    cetak_matriks(matriks_skala);

    // Hasil Skala 3D
    std::cout << "Hasil Skala 3D:\n";
    std::vector<double> hasil_skala_3d = {titik[0] * Sx, titik[1] * Sy, titik[2] * Sz, 1};
    cetak_titik(hasil_skala_3d);

    return hasil_skala_3d;
}

// Fungsi untuk melakukan rotasi 3D
std::vector<double> rotasi_3d(const std::vector<double>& titik, double sudut, char sumbu) {
    double radian = sudut * M_PI / 180.0;
    double cos_theta = cos(radian);
    double sin_theta = sin(radian);

    std::vector<std::vector<double>> matriks_rotasi;

    if (sumbu == 'x') {
        matriks_rotasi = {{1, 0, 0, 0},
                          {0, cos_theta, -sin_theta, 0},
                          {0, sin_theta, cos_theta, 0},
                          {0, 0, 0, 1}};
    } else if (sumbu == 'y') {
        matriks_rotasi = {{cos_theta, 0, sin_theta, 0},
                          {0, 1, 0, 0},
                          {-sin_theta, 0, cos_theta, 0},
                          {0, 0, 0, 1}};
    } else if (sumbu == 'z') {
        matriks_rotasi = {{cos_theta, -sin_theta, 0, 0},
                          {sin_theta, cos_theta, 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    }

    cetak_matriks(matriks_rotasi);

    // Hasil Rotasi 3D
    std::cout << "Hasil Rotasi 3D:\n";
    std::vector<double> hasil_rotasi_3d = {titik[0], titik[1], titik[2], 1};
    cetak_titik(hasil_rotasi_3d);

    return hasil_rotasi_3d;
}

// Fungsi untuk melakukan mirror 3D
std::vector<double> mirror_3d(const std::vector<double>& titik, char sumbu) {
    std::vector<std::vector<double>> matriks_mirror;

    if (sumbu == 'x') {
        matriks_mirror = {{1, 0, 0, 0},
                          {0, -1, 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    } else if (sumbu == 'y') {
        matriks_mirror = {{-1, 0, 0, 0},
                          {0, 1, 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    } else if (sumbu == 'z') {
        matriks_mirror = {{1, 0, 0, 0},
                          {0, 1, 0, 0},
                          {0, 0, -1, 0},
                          {0, 0, 0, 1}};
    }

    cetak_matriks(matriks_mirror);

    // Hasil Mirror 3D
    std::cout << "Hasil Mirror 3D:\n";
    std::vector<double> hasil_mirror_3d;

    if (sumbu == 'x') {
        hasil_mirror_3d = {titik[0], -titik[1], titik[2], 1};
    } else if (sumbu == 'y') {
        hasil_mirror_3d = {-titik[0], titik[1], titik[2], 1};
    } else if (sumbu == 'z') {
        hasil_mirror_3d = {titik[0], titik[1], -titik[2], 1};
    }

    cetak_titik(hasil_mirror_3d);

    return hasil_mirror_3d;
}

// Fungsi untuk melakukan composite transformation 3D
std::vector<double> composite_3d(const std::vector<double>& titik, double tx, double ty, double tz,
                                double Sx, double Sy, double Sz, double sudut, char sumbu) {
    std::vector<double> hasil_translasi_3d = translasi_3d(titik, tx, ty, tz);
    std::vector<double> hasil_skala_3d = skala_3d(hasil_translasi_3d, Sx, Sy, Sz);
    std::vector<double> hasil_rotasi_3d = rotasi_3d(hasil_skala_3d, sudut, sumbu);

    // Hasil Composite Transformation 3D
    std::cout << "Hasil Composite Transformation 3D:\n";
    cetak_titik(hasil_rotasi_3d);

    return hasil_rotasi_3d;
}

int main() {
    double x, y, z;
    std::cout << "Masukkan koordinat titik (x, y, z): ";
    std::cin >> x >> y >> z;

    std::vector<double> titik = {x, y, z, 1};

    int pilihan;
    std::cout << "Pilih transformasi:\n";
    std::cout << "1. Translasi 3D\n";
    std::cout << "2. Skala 3D\n";
    std::cout << "3. Rotasi 3D\n";
    std::cout << "4. Mirror 3D\n";
    std::cout << "5. Composite 3D\n";
    std::cout << "Masukkan nomor transformasi: ";
    std::cin >> pilihan;

    switch (pilihan) {
        case 1: {
            double tx, ty, tz;
            std::cout << "Masukkan faktor translasi X: ";
            std::cin >> tx;
            std::cout << "Masukkan faktor translasi Y: ";
            std::cin >> ty;
            std::cout << "Masukkan faktor translasi Z: ";
            std::cin >> tz;
            translasi_3d(titik, tx, ty, tz);
            break;
        }
        case 2: {
            double Sx, Sy, Sz;
            std::cout << "Masukkan faktor skala X: ";
            std::cin >> Sx;
            std::cout << "Masukkan faktor skala Y: ";
            std::cin >> Sy;
            std::cout << "Masukkan faktor skala Z: ";
            std::cin >> Sz;
            skala_3d(titik, Sx, Sy, Sz);
            break;
        }
        case 3: {
            double sudut;
            char sumbu;
            std::cout << "Masukkan sudut rotasi (derajat): ";
            std::cin >> sudut;
            std::cout << "Pilih sumbu rotasi (x, y, z): ";
            std::cin >> sumbu;
            rotasi_3d(titik, sudut, sumbu);
            break;
        }
        case 4: {
            char sumbu_mirror;
            std::cout << "Pilih sumbu mirror (x, y, z): ";
            std::cin >> sumbu_mirror;
            mirror_3d(titik, sumbu_mirror);
            break;
        }
        case 5: {
            double tx, ty, tz, Sx, Sy, Sz, sudut;
            char sumbu;
            std::cout << "Masukkan faktor translasi X: ";
            std::cin >> tx;
            std::cout << "Masukkan faktor translasi Y: ";
            std::cin >> ty;
            std::cout << "Masukkan faktor translasi Z: ";
            std::cin >> tz;
            std::cout << "Masukkan faktor skala X: ";
            std::cin >> Sx;
            std::cout << "Masukkan faktor skala Y: ";
            std::cin >> Sy;
            std::cout << "Masukkan faktor skala Z: ";
            std::cin >> Sz;
            std::cout << "Masukkan sudut rotasi (derajat): ";
            std::cin >> sudut;
            std::cout << "Pilih sumbu rotasi (x, y, z): ";
            std::cin >> sumbu;

            composite_3d(titik, tx, ty, tz, Sx, Sy, Sz, sudut, sumbu);
            break;
        }
        default:
            std::cout << "Pilihan tidak valid.\n";
            break;
    }

    return 0;
}
