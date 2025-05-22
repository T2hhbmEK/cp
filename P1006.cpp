#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
const int N = 55;
int m, n;
int a[N][N], f[2 * N][N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    rep(i, 1, m) rep(j, 1, n) cin >> a[i][j];
    f[2][1][1] = a[1][1];
    rep(step, 3, n + m - 1) {
        rep(i1, max(1, step - n), min(m, step)) {
            rep(i2, i1 + 1, min(m, step)) {
                f[step][i1][i2] = max({
                    f[step - 1][i1][i2],          // DOWN, DOWN
                    f[step - 1][i1][i2 - 1],      // DOWN, RIGHT
                    f[step - 1][i1 - 1][i2],      // RIGHT, DOWN
                    f[step - 1][i1 - 1][i2 - 1],  // RIGHT, RIGHT
                });
                f[step][i1][i2] += a[i1][step - i1] + a[i2][step - i2];
            }
        }
    }
    f[n + m][m][m] = f[n + m - 1][m][m - 1] + f[n + m - 1][m - 1][m] + a[m][n];
    cout << f[n + m][m][m];
    return 0;
}
