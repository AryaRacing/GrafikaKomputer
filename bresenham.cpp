#include <iostream>
#include <cmath>

using namespace std;

void setPixel(int x, int y) {
    cout << "(" << x << ", " << y << ")" << endl;
}

void bresenham(int xa, int ya, int xb, int yb) {
    int dx = abs(xb - xa);
    int dy = abs(yb - ya);
    int p = 2 * dy - dx;
    int duaDy = 2 * dy;
    int duaDyDx = 2 * (dy - dx);

    int x, y, xEnd;

    // Determine which point to start from
    if (xa > xb) {
        x = xb;
        y = yb;
        xEnd = xa;
    } else {
        x = xa;
        y = ya;
        xEnd = xb;
    }

    setPixel(x, y);

    while (x < xEnd) {
        x++;
        if (p < 0) {
            p += duaDy;
        } else {
            y++;
            p += duaDyDx;
        }
        setPixel(x, y);
    }
}

int main() {
    int xa, ya, xb, yb;
    
    cout << "Algoritma bresenham garis\n";

    cout << "Masukan koordinat awal (xa, ya): ";
    cin >> xa >> ya;

    cout << "Masukan koordinat akhir (xb, yb): ";
    cin >> xb >> yb;

    cout << "Koordinat Garis:" << endl;
    bresenham(xa, ya, xb, yb);

    return 0;
}

