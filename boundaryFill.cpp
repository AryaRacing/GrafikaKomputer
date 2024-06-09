#include <iostream>
#include <vector>

using namespace std;

// Ukuran window
const int WIDTH = 10;
const int HEIGHT = 10;

// Fungsi untuk mendapatkan warna piksel pada koordinat (x, y)
char getPixel(const vector<vector<char> >& image, int x, int y) {
    return image[y][x];
}

// Fungsi untuk mengatur warna piksel pada koordinat (x, y)
void setPixel(vector<vector<char> >& image, int x, int y, char color) {
    image[y][x] = color;
}

// Fungsi Boundary Fill
void BoundaryFill(vector<vector<char> >& image, int x, int y, char fillColor, char boundaryColor) {
    char current = getPixel(image, x, y);
    if ((current != boundaryColor) && (current != fillColor)) {
        setPixel(image, x, y, fillColor);
        BoundaryFill(image, x + 1, y, fillColor, boundaryColor);
        BoundaryFill(image, x - 1, y, fillColor, boundaryColor);
        BoundaryFill(image, x, y + 1, fillColor, boundaryColor);
        BoundaryFill(image, x, y - 1, fillColor, boundaryColor);
    }
}

int main() {
    // Membuat citra representasi sederhana
    vector<vector<char> > image(HEIGHT, vector<char>(WIDTH, '.'));

    // Mendapatkan input dari pengguna
    int x, y;
    char fillColor = 'X'; // Karakter untuk warna isi
    char boundaryColor = '*'; // Karakter untuk warna batas

    cout << "Enter starting coordinates (x y): ";
    cin >> x >> y;

    // Menggambar batas
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                image[i][j] = boundaryColor;
            }
        }
    }

    // Menjalankan Boundary Fill
    BoundaryFill(image, x, y, fillColor, boundaryColor);

    // Menampilkan citra
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

