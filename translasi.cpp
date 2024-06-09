#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

Point translate(Point p, int tx, int ty) {
    Point result;
    result.x = p.x + tx;
    result.y = p.y + ty;
    return result;
}

int main() {
    int numPoints;
    
    cout << "Algoritma translasi\n";
    cout << "Masukkan jumlah titik: ";
    cin >> numPoints;

    vector<Point> points(numPoints);
    vector<Point> translatedPoints(numPoints);

    cout << "Masukkan koordinat titik-titik:\n";
    for (int i = 0; i < numPoints; ++i) {
        cout << "Titik " << i + 1 << " (x y): ";
        cin >> points[i].x >> points[i].y;
    }

    int tx, ty;
    cout << "Masukkan vektor translasi (tx ty): ";
    cin >> tx >> ty;

    for (int i = 0; i < numPoints; ++i) {
        translatedPoints[i] = translate(points[i], tx, ty);
    }

    cout << "\nHasil Translasi:\n";
    for (int i = 0; i < numPoints; ++i) {
        cout << "Titik awal (" << points[i].x << ", " << points[i].y << ") "
             << "-> Titik hasil translasi (" << translatedPoints[i].x << ", " << translatedPoints[i].y << ")\n";
    }

    return 0;
}

