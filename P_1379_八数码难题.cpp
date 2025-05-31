#include <bits/stdc++.h>
#define maxn 5
#define fi first
#define se second
using namespace std;
int s, e = 123804765;
queue<pair<int, int>> q;
map<int, int> mp[2];
int a[maxn][maxn];
int dr[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void seta(int n, int a[maxn][maxn], int &x, int &y) {
    for (int i = 3; i >= 1; i--) {
        for (int j = 3; j >= 1; j--) {
            a[i][j] = n % 10;
            if (a[i][j] == 0) x = i, y = j;
            n /= 10;
        }
    }
}

int getn() {
    int ret = 0;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            ret = ret * 10 + a[i][j];
        }
    }
    return ret;
}

void prt(int n) {
    int a[maxn][maxn], x, y;
    seta(n, a, x, y);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << x << " " << y << endl;
}

int bfs() {
    mp[0][s] = 0, mp[1][e] = 0;
    q.push({s, 0}), q.push({e, 1});
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int n = cur.fi, f = cur.second, x, y;
        seta(n, a, x, y);
        if (mp[!f].count(n)) {
            return mp[f][n] + mp[!f][n];
        }
        // prt(n);
        // cout << mp[f][n] << endl;
        for (int i = 0; i < 4; i++) {
            int nx = x + dr[i][0];
            int ny = y + dr[i][1];
            if (nx >= 1 && nx <= 3 && ny >= 1 && ny <= 3) {
                swap(a[x][y], a[nx][ny]);
                int nn = getn();
                if (!mp[f].count(nn)) {
                    mp[f][nn] = mp[f][n] + 1;
                    q.push({nn, f});
                }
                swap(a[x][y], a[nx][ny]);
            }
        }
    }
    return -1;
}

int main() {
    cin >> s;
    cout << bfs() << endl;
    return 0;
}
