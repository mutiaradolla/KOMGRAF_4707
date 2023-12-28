#include <iostream>

using namespace std;

int main() {
  // Deklarasi variabel
  float x1, y1, z1, x2, y2, z2, x_min, y_min, z_min, x_max, y_max, z_max;
  float m;

  // Input data
  cout << "Masukkan koordinat ujung kiri garis (x1, y1, z1): ";
  cin >> x1 >> y1 >> z1;
  cout << "Masukkan koordinat ujung kanan garis (x2, y2, z2): ";
  cin >> x2 >> y2 >> z2;
  cout << "Masukkan koordinat batas gambar (x_min, y_min, z_min, x_max, y_max, z_max): ";
  cin >> x_min >> y_min >> z_min >> x_max >> y_max >> z_max;

  // Hitung gradien garis
  m = (y2 - y1) / (x2 - x1);

  // Hitung titik potong
  float xp1 = x1 + (y_min - y1) / m;
  float yp1 = y1 + m * (x_min - x1);
  float zp1 = z1 + m * (x_min - x1); // Penambahan sumbu z
  float xp2 = x1 + (y_max - y1) / m;
  float yp2 = y1 + m * (x_max - x1);
  float zp2 = z1 + m * (x_max - x1); // Penambahan sumbu z

  // Tampilkan hasil perhitungan
  cout << "xp1 = " << xp1 << endl;
  cout << "yp1 = " << yp1 << endl;
  cout << "zp1 = " << zp1 << endl;
  cout << "xp2 = " << xp2 << endl;
  cout << "yp2 = " << yp2 << endl;
  cout << "zp2 = " << zp2 << endl;

  // Cetak titik potong
  cout << "(x_min , yp1, zp1) = (" << x_min << ", " << yp1 << ", " << zp1 << ")" << endl;
  cout << "(x_max , yp2, zp2) = (" << x_max << ", " << yp2 << ", " << zp2 << ")" << endl;
  cout << "(xp1 , y_min, zp1) = (" << xp1 << ", " << y_min << ", " << zp1 << ")" << endl;
  cout << "(xp2 , y_max, zp2) = (" << xp2 << ", " << y_max << ", " << zp2 << ")" << endl;

  return 0;
}
