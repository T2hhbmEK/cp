#include <cstring>
#include <iostream>
#define maxn 2048
using namespace std;
char a[maxn][maxn];
bool rm[maxn][maxn];
void draw(int i, int j, int x, int y, int h) {
  a[x][y] = 'o';
  if (h == 1) return;
  int nh = h / 2;
  int d = h - nh;
  int ni = i + 1, nj = 2 * j - 1;
  if (!rm[ni][nj]) {
    int nx = x + d, ny = y - d;
    for (int u = x + 1, v = y - 1; u < nx; ++u, --v) a[u][v] = '/';
    draw(ni, nj, nx, ny, nh);
  }
  nj += 1;
  if (!rm[ni][nj]) {
    int nx = x + d, ny = y + d;
    for (int u = x + 1, v = y + 1; u < nx; ++u, ++v) a[u][v] = '\\';
    draw(ni, nj, nx, ny, nh);
  }
}
int main() {
  memset(a, ' ', sizeof(a));
  int m, n;
  cin >> m >> n;
  while (n--) {
    int i, j;
    cin >> i >> j;
    rm[i][j] = 1;
  }
  int h = 3 * (1 << (m - 2));  // height of canvas
  int w = h * 2 - 1;           // width of canvas
  draw(1, 1, 0, h - 1, h);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
