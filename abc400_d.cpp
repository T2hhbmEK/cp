#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N = 1e3 + 10;
int n, m;
int mz[N][N];
int a, b, c, d;
int dr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dr2[8][2] = {{-1, 0}, {-2, 0}, {1, 0}, {2, 0},
                 {0, -1}, {0, -2}, {0, 1}, {0, 2}};
int f[N * N];
queue<pair<int, int>> q;

inline bool isIn(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int k) {
    q.push({x, y});
    mz[x][y] = k;
    for (int i = 0; i < 4; i++) {
        int nx = x + dr[i][0];
        int ny = y + dr[i][1];
        if (isIn(nx, ny) && mz[nx][ny] < 0) {
            dfs(nx, ny, k);
        }
    }
}

void prt() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mz[i][j] << "";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                mz[i][j] = -1;  // road
            } else {
                mz[i][j] = 0;  // wall
            }
        }
    }
    cin >> a >> b >> c >> d;
    int k = 1;
    dfs(a, b, k);
    while (mz[c][d] < 0) {
        k = k + 1;
        queue<pair<int, int>> pq;  // prev q
        swap(pq, q);
        while (!pq.empty()) {
            auto p = pq.front();
            pq.pop();
            for (int i = 0; i < 8; i++) {
                int nx = p.first + dr2[i][0];
                int ny = p.second + dr2[i][1];
                if (isIn(nx, ny) && mz[nx][ny] == 0) {
                    dfs(nx, ny, k);
                }
            }
        }
    }
    cout << mz[c][d] - 1;
    return 0;
}
