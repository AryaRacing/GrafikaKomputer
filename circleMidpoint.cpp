#include <iostream>
#include <iomanip>
using namespace std;

void plotCirclePoints(int xCenter, int yCenter, int x, int y) {
    cout << "| " << setw(2) << x << " | " << setw(2) << y << " |";
    cout << " (" << setw(3) << xCenter + x << "," << setw(3) << yCenter + y << ") ";
    cout << " (" << setw(3) << xCenter - x << "," << setw(3) << yCenter + y << ") ";
    cout << " (" << setw(3) << xCenter + x << "," << setw(3) << yCenter - y << ") ";
    cout << " (" << setw(3) << xCenter - x << "," << setw(3) << yCenter - y << ") ";
    cout << " (" << setw(3) << xCenter + y << "," << setw(3) << yCenter + x << ") ";
    cout << " (" << setw(3) << xCenter - y << "," << setw(3) << yCenter + x << ") ";
    cout << " (" << setw(3) << xCenter + y << "," << setw(3) << yCenter - x << ") ";
    cout << " (" << setw(3) << xCenter - y << "," << setw(3) << yCenter - x << ") ";
    cout << "|" << endl;
}

void circleMidPoint(int xCenter, int yCenter, int radius) {
    int x = 0;
    int y = radius;
    int p = 1 - radius;
    
    

    cout << "+----+----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+" << endl;
    cout << "|  x |  y |    (x0, y0)     |    (-x0, y0)    |    (x0, -y0)    |    (-x0, -y0)   |    (y0, x0)     |    (-y0, x0)    |    (y0, -x0)    |    (-y0, -x0)   |" << endl;
    cout << "+----+----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+" << endl;

    plotCirclePoints(xCenter, yCenter, x, y);

    while (x < y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * x - 2 * y + 1;
        }
        plotCirclePoints(xCenter, yCenter, x, y);
    }

    cout << "+----+----+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+-----------------+" << endl;
}

int main() {
    int xCenter, yCenter, radius;
    
    cout << "Algoritma circle midpoint\n";

    cout << "Masukkan koordinat pusat lingkaran (xCenter, yCenter): ";
    cin >> xCenter >> yCenter;

    cout << "Masukkan radius lingkaran: ";
    cin >> radius;

    cout << "Tabel Koordinat Lingkaran:\n";
    circleMidPoint(xCenter, yCenter, radius);

    return 0;
}

