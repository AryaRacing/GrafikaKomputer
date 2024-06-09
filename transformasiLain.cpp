#include <iostream>

using namespace std;

struct Titik {
  double x;
  double y;
};

Titik refleksikanTitikX(Titik p) {
  p.y *= -1;
  return p;
}

Titik refleksikanTitikY(Titik p) {
  p.x *= -1;
  return p;
}

Titik refleksikanTitikDiagonal(Titik p) {
  double temp = p.x;
  p.x = p.y;
  p.y = temp;
  return p;
}

Titik refleksikanTitikPerpendicular(Titik p) {
  p.x *= -1;
  p.y *= -1;
  return p;
}

void cetakSegitiga(Titik p1, Titik p2, Titik p3) {
  cout << "Koordinat segitiga:" << endl;
  cout << "  - Titik 1: (" << p1.x << ", " << p1.y << ")" << endl;
  cout << "  - Titik 2: (" << p2.x << ", " << p2.y << ")" << endl;
  cout << "  - Titik 3: (" << p3.x << ", " << p3.y << ")" << endl;
}

int main() {
  
  Titik p1 = {1, 2};
  Titik p2 = {3, 2};
  Titik p3 = {2, 1};

  cout << "Segitiga asli:" << endl;
  cetakSegitiga(p1, p2, p3);

  cout << "\nRefleksi terhadap sumbu x:" << endl;
  Titik reflekX[3] = {refleksikanTitikX(p1), refleksikanTitikX(p2), refleksikanTitikX(p3)};
  cetakSegitiga(reflekX[0], reflekX[1], reflekX[2]);

  cout << "\nRefleksi terhadap sumbu y:" << endl;
  Titik reflekY[3] = {refleksikanTitikY(p1), refleksikanTitikY(p2), refleksikanTitikY(p3)};
  cetakSegitiga(reflekY[0], reflekY[1], reflekY[2]);

  cout << "\nRefleksi terhadap garis diagonal (y = x):" << endl;
  Titik reflekDiagonal[3] = {refleksikanTitikDiagonal(p1), refleksikanTitikDiagonal(p2), refleksikanTitikDiagonal(p3)};
  cetakSegitiga(reflekDiagonal[0], reflekDiagonal[1], reflekDiagonal[2]);

  cout << "\nRefleksi terhadap sumbu tegak lurus bidang xy:" << endl;
  Titik reflekPerpendicular[3] = {refleksikanTitikPerpendicular(p1), refleksikanTitikPerpendicular(p2), refleksikanTitikPerpendicular(p3)};
  cetakSegitiga(reflekPerpendicular[0], reflekPerpendicular[1], reflekPerpendicular[2]);

  return 0;
}

