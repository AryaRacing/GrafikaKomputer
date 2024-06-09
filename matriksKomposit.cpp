#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void rotateTriangle(vector<pair<double, double> >& vertices, double angle) {
    double radians = angle * M_PI / 180.0;

    double cosTheta = cos(radians);
    double sinTheta = sin(radians);
    double rotationMatrix[2][2] = {
        {cosTheta, -sinTheta},
        {sinTheta, cosTheta}
    };

    double pivotX = 0.0, pivotY = 0.0;
    for (int i = 0; i < vertices.size(); ++i) {
        pivotX += vertices[i].first;
        pivotY += vertices[i].second;
    }
    pivotX /= vertices.size();
    pivotY /= vertices.size();

    for (int i = 0; i < vertices.size(); ++i) {
        double x = vertices[i].first - pivotX;
        double y = vertices[i].second - pivotY;

        double newX = x * rotationMatrix[0][0] + y * rotationMatrix[0][1];
        double newY = x * rotationMatrix[1][0] + y * rotationMatrix[1][1];

        vertices[i].first = newX + pivotX;
        vertices[i].second = newY + pivotY;
    }
}

int main() {
    vector<pair<double, double> > vertices;
    vertices.push_back(make_pair(1.0, 2.0));
    vertices.push_back(make_pair(3.0, 4.0));
    vertices.push_back(make_pair(5.0, 2.0));

    double angle = 45.0;

    rotateTriangle(vertices, angle);

    cout << "Transformed triangle vertices:\n";
    for (int i = 0; i < vertices.size(); ++i) {
        cout << "(" << vertices[i].first << ", " << vertices[i].second << ")" << endl;
    }

    return 0;
}

