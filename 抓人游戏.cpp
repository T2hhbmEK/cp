#include <bits/stdc++.h>
using namespace std;

const int NMAX = 100 + 7;
const int TMAX = 1000 + 7;

int n, tn;
char m[NMAX][NMAX];
bool vis[NMAX][NMAX];
int dis[NMAX][NMAX];  // 记录到达每个点的步数
struct Pos {
    int x, y;
} pb[TMAX];  // 每个时刻，B 的位置
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
queue<Pos> q;

void bfs() {
    while (!q.empty()) {
        Pos cur = q.front();
        q.pop();

        int d = dis[cur.x][cur.y];
        if (cur.x == pb[d].x && cur.y == pb[d].y) {
            cout << d;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            Pos nxt;
            nxt.x = cur.x + dir[i][0];
            nxt.y = cur.y + dir[i][1];
            dis[nxt.x][nxt.y] = d + 1;
            if (vis[nxt.x][nxt.y] == 0 && m[nxt.x][nxt.y] == '.') {
                vis[nxt.x][nxt.y] = 1;
                q.push(nxt);
            }
        }
    }

    cout << -1;
}

int main() {
    cin >> n >> tn;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 'A') {
                q.push((Pos){i, j});
                vis[i][j] = 1;
            } else if (m[i][j] == 'B') {
                pb[0].x = i;
                pb[0].y = j;
                m[i][j] = '.';  // 让终点是没有障碍的
            }
        }
    }
    for (int i = 1; i <= tn; ++i) {
        cin >> pb[i].x >> pb[i].y;
    }
    bfs();
    return 0;
}
