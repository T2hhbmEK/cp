#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 105, maxm = 105, mod = 1e6 + 7;
int n, m, a[maxn], f[maxm];

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= a[i] && j - k >= 0; k++) {
                (f[j] += f[j - k]) %= mod;
            }
        }
    }
    cout << f[m] << '\n';
    return 0;
}
