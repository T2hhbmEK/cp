#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll llinf = 0x3f3f3f3f3f3f3f3fll;

enum DIRECTION {
    UP,
    DOWN,
    RIGHT,
};

struct pos {
    int i, j;
};

int n, m;
vector<pos> dir = {
    {-1, 0},  // UP
    {1, 0},   // DOWN
    {0, 1},   // RIGHT
};
vector<vector<int>> a;
ll ans = -llinf, sum;
vector<vector<vector<ll>>> f;

void dfs(int i, int j, DIRECTION d) {
    if (sum <= f[i][j][d]) {
        return;  // Pruning
    }
    if (i == n && j == m) {
        ans = max(ans, sum);
        return;
    }
    for (int k = UP; k <= RIGHT; ++k) {
        int ni = i + dir[k].i, nj = j + dir[k].j;
        if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
            if (k == UP && d == DOWN || k == DOWN && d == UP) {
                continue;
            }
            sum += a[ni][nj];
            dfs(ni, nj, static_cast<DIRECTION>(k));
            sum -= a[ni][nj];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> n >> m;
    a.assign(n + 1, vector<int>(m + 1));
    f.assign(n + 2, vector<vector<ll>>(m + 2, vector<ll>(3, -llinf)));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    sum = a[1][1];
    dfs(1, 1, RIGHT);
    cout << ans << endl;
    return 0;
}
