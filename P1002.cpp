#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;

const int maxn = 25;
int n, m, cx, cy, ans, a[maxn][maxn];

inline bool isIn(int x, int y) {
    return x >= 0 && x <= n && y >= 0 && y <= m;
}

signed main() {
    scanf("%lld%lld%lld%lld", &n, &m, &cx, &cy);
    a[cx][cy] = -1;
    for (int dx : {-1, 1}) {
        for (int dy : {-1, 1}) {
            if (isIn(cx + dx * 2, cy + dy)) a[cx + dx * 2][cy + dy] = -1;
            if (isIn(cx + dx, cy + dy * 2)) a[cx + dx][cy + dy * 2] = -1;
        }
    }
    a[0][0] = 1;
    rep(i, 0, n) rep(j, 0, m) {
        if (a[i][j] >= 0) {
            if (i >= 1 && a[i - 1][j] >= 0) a[i][j] += a[i - 1][j];
            if (j >= 1 && a[i][j - 1] >= 0) a[i][j] += a[i][j - 1];
        }
    }
    printf("%lld\n", a[n][m]);
    return 0;
}
