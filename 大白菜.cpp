#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;

int n, m;
int a[maxn][maxn];
int b[maxn][maxn];

void solve() {
    // 二维前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] = b[i][j - 1] + a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[i][j] = b[i - 1][j] + b[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0) continue;
            for (int k = ans + 1; k <= n; ++k) {
                int x = i + k - 1, y = j + k - 1;
                if (x > n || y > m) break;
                // 判断是否为白菜地
                int sum = b[x][y] - b[i - 1][y] - b[x][j - 1] + b[i - 1][j - 1];
                if (sum == k * k) {
                    ans = k;
                } else {
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
    freopen("cabbage.in", "r", stdin);
    freopen("cabbage.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    solve();
    return 0;
}
