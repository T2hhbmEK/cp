#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 100;
const int MOD = 1e4;
int n, m, a[N][N];
__int128 ans, f[N];

ostream& operator<<(ostream& os, __int128 x) {
    if (x < 0) {
        os << '-';
        x = -x;
    }
    if (x > 9) os << x / 10;
    return os << (int)(x % 10);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        memset(f, 0, sizeof(f));
        for (int len = 1; len <= m; len++) {
            for (int j = 1; j + len - 1 <= m; j++) {
                __int128 L = a[i][j] + f[j + 1];
                __int128 R = f[j] + a[i][j + len - 1];
                f[j] = max(L * 2, R * 2);
            }
        }
        ans += f[1];
    }
    cout << ans;
    return 0;
}
