#include <iostream>
#include <vector>

using namespace std;

void skalaGambar(vector<pair<int, int> > titikAsli, float sx, float sy) {

  int n = titikAsli.size();

  vector<pair<int, int> > titikBaru(n);
  for (int i = 0; i < n; i++) {
    int x = titikAsli[i].first;
    int y = titikAsli[i].second;
    int x_baru = x * sx;
    int y_baru = y * sy;
    titikBaru[i] = make_pair(x_baru, y_baru);
  }

  cout << "Koordinat gambar yang telah diskalakan:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Titik " << i + 1 << ": (" << titikBaru[i].first << ", " << titikBaru[i].second << ")" << endl;
  }
}

int main() {

  int n;
  
  cout << "Algoritma Skala\n";
  cout << "Masukkan jumlah titik: ";
  cin >> n;

  vector<pair<int, int> > titikAsli(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cout << "Masukkan koordinat titik " << i + 1 << " (x, y): ";
    cin >> x >> y;
    titikAsli[i] = make_pair(x, y);
  }

  float sx, sy;
  cout << "Masukkan faktor skala sx & sy: ";
  cin >> sx >> sy;

  skalaGambar(titikAsli, sx, sy);

  return 0;
}

