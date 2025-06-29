#include <cstring>
#include <iostream>
#define maxn 1510
using namespace std;
int n, m, sx, sy;
char a[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
template <typename T>
void output(T a[maxn][maxn]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
struct State {
  int v, x, y;
  bool operator!=(const State& o) const {
    return v != o.v || x != o.x || y != o.y;
  }
};
State vis[maxn][maxn];
bool dfs(int x, int y) {
  int cx = (x % n + n) % n, cy = (y % m + m) % m;
  if (vis[cx][cy].v) return true;
  vis[cx][cy] = {1, x, y};
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i], ny = y + dy[i];
    int ncx = (nx % n + n) % n, ncy = (ny % m + m) % m;
    if (a[ncx][ncy] != '#' && vis[ncx][ncy] != State{1, nx, ny}) {
      if (dfs(nx, ny)) return true;
    }
  }
  return false;
}
int main() {
  while (cin >> n >> m && n > 0 && m > 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if (a[i][j] == 'S') sx = i, sy = j;
      }
    }
    memset(vis, 0, sizeof(vis));
    if (dfs(sx, sy)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
    // output(a);
    // output(vis);
  }
  return 0;
}
