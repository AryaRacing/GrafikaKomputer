#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void rotasiGambar(pair<int, int> titikPivot, float sudutRotasi, vector<pair<int, int> > titikAsli) {

  int n = titikAsli.size();

  float sinTeta = sin(sudutRotasi * M_PI / 180.0);
  float cosTeta = cos(sudutRotasi * M_PI / 180.0);

  vector<pair<int, int> > titikBaru(n);
  for (int i = 0; i < n; i++) {
    int x = titikAsli[i].first - titikPivot.first;
    int y = titikAsli[i].second - titikPivot.second;
    int x_baru = x * cosTeta - y * sinTeta + titikPivot.first;
    int y_baru = x * sinTeta + y * cosTeta + titikPivot.second;
    titikBaru[i] = make_pair(x_baru, y_baru);
  }

  cout << "Koordinat gambar yang telah dirotasi:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Titik " << i + 1 << ": (" << titikBaru[i].first << ", " << titikBaru[i].second << ")" << endl;
  }
}

int main() {
  int x_pivot, y_pivot;
  
  cout << "Algoritma rotasi\n";
  cout << "Masukkan koordinat titik pivot (x, y): ";
  cin >> x_pivot >> y_pivot;
  pair<int, int> titikPivot = make_pair(x_pivot, y_pivot);

  float sudutRotasi;
  cout << "Masukkan sudut rotasi (dalam derajat): ";
  cin >> sudutRotasi;

  int n;
  cout << "Masukkan jumlah titik: ";
  cin >> n;
  vector<pair<int, int> > titikAsli(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cout << "Masukkan koordinat titik " << i + 1 << " (x, y): ";
    cin >> x >> y;
    titikAsli[i] = make_pair(x, y);
  }

  rotasiGambar(titikPivot, sudutRotasi, titikAsli);

  return 0;
}

