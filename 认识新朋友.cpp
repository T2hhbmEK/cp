#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 7;

int n, m, a, b;
bool f[N][N];  // f[i][j] 表示 i 和 j 是朋友
bool vis[N];
int dis[N];
queue<int> q;

void bfs() {
    q.push(a);  // 从 a 开始搜索
    vis[a] = 1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == b) {  // 到达 b
            cout << dis[b];
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!vis[i] && f[x][i]) {  // x 和 i 是朋友，且 i 没有被访问过
                dis[i] = dis[x] + 1;
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    cout << "!";
}

int main() {
    cin >> n >> m;
    while (m--) {
        int p, q;
        cin >> p >> q;
        f[p][q] = f[q][p] = 1;  // 朋友关系是双向的
    }
    cin >> a >> b;
    bfs();
    return 0;
}
