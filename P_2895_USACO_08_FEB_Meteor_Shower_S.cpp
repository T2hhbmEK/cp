#include <bits/stdc++.h>
#define maxn 310
using namespace std;

struct State {
  int x, y, n;
};

int m, a[maxn][maxn], vis[maxn][maxn];
int dr[5][2] = {
    {0, 0}, {-1, 0}, {0, -1}, {1, 0}, {0, 1},
};
queue<State> q;

int bfs() {
  vis[0][0] = 1;
  q.push({0, 0, 0});
  while (!q.empty()) {
    State cur = q.front();
    q.pop();
    if (a[cur.x][cur.y] < 0) {
      return cur.n;
    }
    for (int k = 1; k <= 4; k++) {
      State nex{
          cur.x + dr[k][0],
          cur.y + dr[k][1],
          cur.n + 1,
      };
      if (nex.x >= 0 && nex.y >= 0 && vis[nex.x][nex.y] == 0) {
        if (a[nex.x][nex.y] < 0 || a[nex.x][nex.y] > nex.n) {
          vis[nex.x][nex.y] = 1;
          q.push(nex);
        }
      }
    }
  }
  return -1;
}

int main() {
  cin >> m;
  memset(a, -1, sizeof(a));
  while (m--) {
    int x, y, t;
    cin >> x >> y >> t;
    for (int i = 0; i <= 4; i++) {
      int nx = x + dr[i][0];
      int ny = y + dr[i][1];
      if (nx >= 0 && ny >= 0) {
        if (a[nx][ny] < 0 || a[nx][ny] > t) {
          a[nx][ny] = t;
        }
      }
    }
  }
  cout << bfs();
  return 0;
}
