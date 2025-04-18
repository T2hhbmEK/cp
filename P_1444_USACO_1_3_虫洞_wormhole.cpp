#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, idx[N], ridx[N], ans;
bool vis[N];
struct P {
    int x, y;
    bool operator<(const P& o) {
        if (y == o.y) return x < o.x;
        return y < o.y;
    }
} a[N];
bool hasLoop() {
    memset(vis, 0, sizeof(vis));
    for (int ii = 0; ii < n; ++ii) {
        int i = idx[ii];
        ridx[i] = ii;
    }
    for (int ii = 0; ii < n; ++ii) {
        int i = idx[ii];
        if (vis[i]) continue;
        int cnt = 0;
        while (cnt++ <= n) {
            int j = i + 1;  // walk
            if (j >= n || a[j].y != a[i].y) break;
            int jj = ridx[j];
            i = idx[jj ^ 1];  // warp
            vis[i] = 1;
        }
        if (cnt > n) return true;
    }
    return false;
}
void p() {
    for (int ii = 0; ii < n; ii += 2) {
        int i = ii;
        int j = ii + 1;
        cout << a[i].x << " " << a[i].y << " <-> ";
        cout << a[j].x << " " << a[j].y << "\n";
    }
    cout << "\n";
}
void dfs(int l) {
    if (l >= n) {
        if (hasLoop()) ++ans;
        return;
    }
    for (int i = l + 1; i < n; ++i) {
        swap(idx[l + 1], idx[i]);
        dfs(l + 2);
        swap(idx[l + 1], idx[i]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    iota(idx, idx + n, 0);
    dfs(0);
    cout << ans;
    return 0;
}