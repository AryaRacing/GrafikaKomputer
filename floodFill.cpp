#include <iostream>
#include <vector>

using namespace std;

// Ukuran window
const int WIDTH = 10;
const int HEIGHT = 10;

// Matriks untuk citra
vector<vector<char> > image(HEIGHT, vector<char>(WIDTH, '.'));

// Fungsi untuk mendapatkan warna piksel pada koordinat (x, y)
char getPixel(int x, int y) {
    return image[y][x];
}

// Fungsi untuk mengatur warna piksel pada koordinat (x, y)
void setPixel(int x, int y, char color) {
    image[y][x] = color;
}

// Fungsi Flood Fill
void FloodFill(int x, int y, char fillColor, char oldColor) {
    char current = getPixel(x, y);
    if (current == oldColor) {
        setPixel(x, y, fillColor);
        FloodFill(x + 1, y, fillColor, oldColor);
        FloodFill(x - 1, y, fillColor, oldColor);
        FloodFill(x, y + 1, fillColor, oldColor);
        FloodFill(x, y - 1, fillColor, oldColor);
    }
}

int main() {
    // Mendapatkan input dari pengguna
    int x, y;
    char fillColor, oldColor;

    cout << "Enter starting coordinates (x y): ";
    cin >> x >> y;

    cout << "Enter fill color: ";
    cin >> fillColor;

    cout << "Enter old color: ";
    cin >> oldColor;

    // Menggambar batas
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                image[i][j] = '*'; // Menggunakan warna batas sebagai nilai default
            }
        }
    }

    // Menjalankan Flood Fill
    FloodFill(x, y, fillColor, oldColor);

    // Menampilkan citra setelah proses Flood Fill
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

