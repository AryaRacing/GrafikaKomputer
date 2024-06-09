#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void display(int xs1, int ys1, int x, int y) {
    cout << "(" << xs1 + x << ", " << ys1 + y << "), ";
    cout << "(" << xs1 - x << ", " << ys1 + y << "), ";
    cout << "(" << xs1 + x << ", " << ys1 - y << "), ";
    cout << "(" << xs1 - x << ", " << ys1 - y << ")\n";
}

void ellips1(int xs1, int ys1, int rx, int ry) {
    int x, y;
    float d1, d2, dx, dy;
    x = 0;
    y = ry;
    d1 = pow(ry, 2) - (pow(rx, 2) * ry) + (0.25 * pow(rx, 2));
    dx = 2 * pow(ry, 2) * x;
    dy = 2 * pow(rx, 2) * y;

    cout << "Region 1:\n";
    do {
        display(xs1, ys1, x, y);
        if (d1 < 0) {
            x++;
            dx = dx + (2 * pow(ry, 2));
            d1 = d1 + dx + pow(ry, 2);
        } else {
            x++;
            y--;
            dx = dx + (2 * pow(ry, 2));
            dy = dy - (2 * pow(rx, 2));
            d1 = d1 + dx - dy + pow(ry, 2);
        }
    } while (dx < dy);

    d2 = (pow(ry, 2) * (pow(x + 0.5, 2))) + (pow(rx, 2) * (pow(y - 1, 2))) - (pow(rx, 2) * pow(ry, 2));
    cout << "Region 2:\n";
    do {
        display(xs1, ys1, x, y);
        if (d2 > 0) {
            y--;
            dy = dy - (2 * pow(rx, 2));
            d2 = d2 + pow(rx, 2) - dy;
        } else {
            y--;
            x++;
            dx = dx + (2 * pow(ry, 2));
            dy = dy - (2 * pow(rx, 2));
            d2 = d2 + dx - dy + pow(rx, 2);
        }
    } while (y >= 0);
}

int main() {
    int xs1, ys1, rx, ry;
    cout << "Algoritma elips midpoint\n";

    cout << "Masukkan koordinat pusat elips (xs1, ys1): ";
    cin >> xs1 >> ys1;

    cout << "Masukkan radius elips di sumbu x (rx): ";
    cin >> rx;

    cout << "Masukkan radius elips di sumbu y (ry): ";
    cin >> ry;

    cout << "Titik-titik elips:\n";
    ellips1(xs1, ys1, rx, ry);

    return 0;
}

