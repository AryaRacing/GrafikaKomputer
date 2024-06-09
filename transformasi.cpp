#include <iostream>
#include <cmath>

using namespace std;

void translasi(float tx, float ty, float *matriks_translasi) {

    matriks_translasi[0] = 1.0; matriks_translasi[1] = 0.0; matriks_translasi[2] = 0.0; matriks_translasi[3] = tx;
    matriks_translasi[4] = 0.0; matriks_translasi[5] = 1.0; matriks_translasi[6] = 0.0; matriks_translasi[7] = ty;
    matriks_translasi[8] = 0.0; matriks_translasi[9] = 0.0; matriks_translasi[10] = 1.0; matriks_translasi[11] = 0.0;
    matriks_translasi[12] = 0.0; matriks_translasi[13] = 0.0; matriks_translasi[14] = 0.0; matriks_translasi[15] = 1.0;
}

void skala(float sx, float sy, float *matriks_skala) {
 
    matriks_skala[0] = sx; matriks_skala[1] = 0.0; matriks_skala[2] = 0.0; matriks_skala[3] = 0.0;
    matriks_skala[4] = 0.0; matriks_skala[5] = sy; matriks_skala[6] = 0.0; matriks_skala[7] = 0.0;
    matriks_skala[8] = 0.0; matriks_skala[9] = 0.0; matriks_skala[10] = 1.0; matriks_skala[11] = 0.0;
    matriks_skala[12] = 0.0; matriks_skala[13] = 0.0; matriks_skala[14] = 0.0; matriks_skala[15] = 1.0;
}

void rotasi(float sudut, float *matriks_rotasi) {
    
    float rad = sudut * M_PI / 180.0; 
    float cosinus = cos(rad);
    float sinus = sin(rad);

    matriks_rotasi[0] = cosinus; matriks_rotasi[1] = -sinus; matriks_rotasi[2] = 0.0; matriks_rotasi[3] = 0.0;
    matriks_rotasi[4] = sinus; matriks_rotasi[5] = cosinus; matriks_rotasi[6] = 0.0; matriks_rotasi[7] = 0.0;
    matriks_rotasi[8] = 0.0; matriks_rotasi[9] = 0.0; matriks_rotasi[10] = 1.0; matriks_rotasi[11] = 0.0;
    matriks_rotasi[12] = 0.0; matriks_rotasi[13] = 0.0; matriks_rotasi[14] = 0.0; matriks_rotasi[15] = 1.0;
}

void perkalian_matriks(float *matriks1, float *matriks2, float *matriks_hasil) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matriks_hasil[i * 4 + j] = 0.0;
            for (int k = 0; k < 4; k++) {
                matriks_hasil[i * 4 + j] += matriks1[i * 4 + k] * matriks2[k * 4 + j];
            }
        }
    }
}

void gabungkan_koordinat_homogen(float *koordinat, float *matriks_transformasi, float *koordinat_hasil) {

    for (int i = 0; i < 4; i++) {
        koordinat_hasil[i] = 0.0;
        for (int j = 0; j < 4; j++) {
            koordinat_hasil[i] += koordinat[j] * matriks_transformasi[i * 4 + j];
        }
    }
}

int main() {

    float koordinat_awal[4] = {1.0, 2.0, 3.0, 1.0}; 
    float tx = 2.0;
    float ty = 3.0; 
    float sudut = 45.0;
    float sx = 0.5;
    float sy = 2.0; 

    float matriks_translasi[16];
    float matriks_rotasi[16];
    float matriks_skala[16];
    float matriks_transformasi_gabungan[16];
    float koordinat_hasil[4];

    translasi(tx, ty, matriks_translasi);
    rotasi(sudut, matriks_rotasi);
    skala(sx, sy, matriks_skala);

    float matriks_sementara[16];
    perkalian_matriks(matriks_translasi, matriks_rotasi, matriks_sementara);
    perkalian_matriks(matriks_sementara, matriks_skala, matriks_transformasi_gabungan);

    gabungkan_koordinat_homogen(koordinat_awal, matriks_transformasi_gabungan, koordinat_hasil);

    cout << "Koordinat awal: (" << koordinat_awal[0] << ", " << koordinat_awal[1] << ", " << koordinat_awal[2] << ", " << koordinat_awal[3] << ")" << endl;
    cout << "Translasi: (" << tx << ", " << ty << ")" << endl;
    cout << "Rotasi: " << sudut << " derajat" << endl;
    cout << "Skala: (" << sx << ", " << sy << ")" << endl;
    cout << "Koordinat hasil: (" << koordinat_hasil[0] << ", " << koordinat_hasil[1] << ", " << koordinat_hasil[2] << ", " << koordinat_hasil[3] << ")" << endl;

    return 0;
}

