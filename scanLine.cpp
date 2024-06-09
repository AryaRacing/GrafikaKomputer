#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int y_max;
    int x_min;
    int dx;
    int dy;
    int sum;
};

bool compare_edges(const Edge& a, const Edge& b) {
    if (a.x_min == b.x_min) {
        return a.y_max < b.y_max;
    }
    return a.x_min < b.x_min;
}

void scan_line_fill(vector<pair<int, int> >& vertices) {
    // Menentukan batas minimum dan maksimum y
    int y_min = INT_MAX;
    int y_max = INT_MIN;
    for (size_t i = 0; i < vertices.size(); ++i) {
        y_min = min(y_min, vertices[i].second);
        y_max = max(y_max, vertices[i].second);
    }

    // Menyiapkan tabel tepi
    vector<vector<Edge> > edge_table(y_max - y_min + 1);

    // Menambahkan tepi ke tabel tepi
    for (size_t i = 0; i < vertices.size(); ++i) {
        int x1 = vertices[i].first;
        int y1 = vertices[i].second;
        int x2 = vertices[(i + 1) % vertices.size()].first;
        int y2 = vertices[(i + 1) % vertices.size()].second;

        if (y1 == y2) continue; // Abaikan garis horizontal

        if (y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }

        int dy = y2 - y1;
        int dx = x2 - x1;
        int x = x1;
        int sum = 0;

        edge_table[y1 - y_min].push_back((Edge){y2, x, dx, dy, sum});
    }

    // Mengurutkan tepi di setiap baris
    for (size_t i = 0; i < edge_table.size(); ++i) {
        sort(edge_table[i].begin(), edge_table[i].end(), compare_edges);
    }

    // Mengisi poligon
    vector<Edge> active_edges;
    for (int y = y_min; y <= y_max; ++y) {
        // Menghapus tepi yang sudah tidak aktif
        vector<Edge>::iterator it = active_edges.begin();
        while (it != active_edges.end()) {
            if (it->y_max <= y) {
                it = active_edges.erase(it);
            } else {
                ++it;
            }
        }

        // Menambahkan tepi yang baru aktif
        for (size_t i = 0; i < edge_table[y - y_min].size(); ++i) {
            active_edges.push_back(edge_table[y - y_min][i]);
        }

        // Mengurutkan active edges
        sort(active_edges.begin(), active_edges.end(), compare_edges);

        // Mengisi piksel dengan warna
        for (size_t i = 0; i < active_edges.size(); i += 2) {
            if (i + 1 >= active_edges.size()) break;
            int x_start = active_edges[i].x_min;
            int x_end = active_edges[i + 1].x_min;

            for (int x = x_start; x < x_end; ++x) {
                // Mengisi piksel dengan warna di buffer gambar
                cout << "(" << x << ", " << y << ") ";
            }
        }

        // Update x untuk active edges
        for (size_t i = 0; i < active_edges.size(); ++i) {
            active_edges[i].sum += active_edges[i].dx;
            while (active_edges[i].sum >= active_edges[i].dy) {
                active_edges[i].x_min++;
                active_edges[i].sum -= active_edges[i].dy;
            }
            while (active_edges[i].sum < 0) {
                active_edges[i].x_min--;
                active_edges[i].sum += active_edges[i].dy;
            }
        }
    }
}

int main() {
    // Contoh daftar titik poligon
    vector<pair<int, int> > vertices;
    vertices.push_back(make_pair(1, 1));
    vertices.push_back(make_pair(5, 1));
    vertices.push_back(make_pair(5, 5));
    vertices.push_back(make_pair(1, 5));

    // Memanggil fungsi scan_line_fill
    scan_line_fill(vertices);

    return 0;
}

