#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
const int maxv = 2e4 + 10;
const int mod = 998244353;
int n, a[maxn], f[maxv], g[maxn], ans;
unordered_set<int> ds, as;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        as.insert(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ds.insert(a[j] - a[i]);
        }
    }
    for (int d : ds) {
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++) {
            int b = a[i] - d;
            if (b >= 0 && b <= 1e4) {
                g[i] = f[b] + 1;
                f[a[i]] += g[i];
            }
            ans += g[i];
        }
        cout << d << " : ";
        for (int i = 1; i <= n; i++) cout << g[i] << " \n"[n == i];
    }
    cout << ans;
    return 0;
}
