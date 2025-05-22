#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, ans = INF;
vector<int> a, b, c, d;

void dfs(int k) {
    if (k > n) {
        vector<int> vis(n + 2);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int j = d[i];
            if (vis[j - 1] && vis[j + 1]) {
                sum += c[j];
            } else if (vis[j - 1] || vis[j + 1]) {
                sum += b[j];
            } else {
                sum += a[j];
            }
            vis[j] = 1;
        }
        ans = min(ans, sum);
        return;
    }
    for (int i = k; i <= n; i++) {
        swap(d[k], d[i]);
        dfs(k + 1);
        swap(d[k], d[i]);
    }
}

void solve1() {
    int sum[2] = {0};
    for (int i = 1; i <= n; i++) {
        sum[i % 2] += a[i];
    }
    cout << min(sum[0], sum[1]);
}

int main() {
    cin >> n;
    if (n > 10) return 0;
    a = vector<int>(n + 1);
    b = vector<int>(n + 1);
    c = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += c[i];
    if (sum == 0) {
        solve1();
        return 0;
    }
    d = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) d[i] = i;
    dfs(1);
    cout << ans;
    return 0;
}
