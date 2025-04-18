#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll inf = 0x3f3f3f3f3f3f3f3fll;

enum DIRECTION {
    UP,
    DOWN,
    RIGHT,
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<vector<ll>>> f(
        n + 2, vector<vector<ll>>(m + 2, vector<ll>(3, -inf)));
    // up down right
    f[1][0][UP] = f[1][0][DOWN] = f[1][0][RIGHT] = 0;
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            // right：from up or down or right
            f[i][j][RIGHT] =
                max({f[i][j - 1][UP], f[i][j - 1][DOWN], f[i][j - 1][RIGHT]});
            if (f[i][j][RIGHT] != -inf) {
                f[i][j][RIGHT] += a[i][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            // down：from down or right
            f[i][j][DOWN] = max(f[i - 1][j][DOWN], f[i - 1][j][RIGHT]);
            if (f[i][j][DOWN] != -inf) {
                f[i][j][DOWN] += a[i][j];
            }
        }
        for (int i = n; i >= 1; --i) {
            // up：from up or right
            f[i][j][UP] = max(f[i + 1][j][UP], f[i + 1][j][RIGHT]);
            if (f[i][j][UP] != -inf) {
                f[i][j][UP] += a[i][j];
            }
        }
    }
    cout << max({f[n][m][UP], f[n][m][DOWN], f[n][m][RIGHT]}) << endl;
    return 0;
}
