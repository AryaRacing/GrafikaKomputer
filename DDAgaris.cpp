#include <iostream>
#include <cmath>

using namespace std;

void dda(int x0, int y0, int x1, int y1) {

    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float x_inc = (float) dx / steps;
    float y_inc = (float) dy / steps;

    float x = (float) x0;
    float y = (float) y0;

    cout << "Koordinat Garis:\n";

    for (int i = 0; i <= steps; i++) {
        int rounded_x = (int) round(x);
        int rounded_y = (int) round(y);

        cout << "(" << rounded_x << ", " << rounded_y << ")" << endl;

        x += x_inc;
        y += y_inc;
    }
}

int main() {
    int x0, y0, x1, y1;
    
    cout <<"Algoritma DDA Garis\n";

    cout << "Masukan koordinat awal (x0, y0): ";
    cin >> x0 >> y0;

    cout << "Masukan koordinat akhir (x1, y1): ";
    cin >> x1 >> y1;

    dda(x0, y0, x1, y1);

    return 0;
}

