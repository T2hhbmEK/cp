#include <bits/stdc++.h>
#define int long long
#define maxn 55
using namespace std;

int n, ans, t;
int x[maxn], y[maxn];
int d[maxn][maxn];
int vis[maxn];

inline int dis(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void dfs(int k, int t) {  // O(n^2)
    if (vis[k]) return;
    vis[k] = 1;
    for (int i = 1; i <= n; i++) {
        if (i == k) continue;
        if (d[k][i] <= 2 * t) {
            dfs(i, t);
        }
    }
}

bool chk(int t) {
    memset(vis, 0, sizeof(vis));
    dfs(1, t);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) return 0;
    }
    return 1;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = dis(i, j);
        }
    }
    int L = 0, R = 1e9;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (chk(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
