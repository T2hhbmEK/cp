#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5e5 + 10;
int n, x, ans;
int a[MAXN];
int f[MAXN];

void solve() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int l = n; l >= 1; l--) {
        int r = upper_bound(a + l, a + n + 1, a[l - 1] + x) - a;
        f[l] = r - l + f[r + 1];
        // cout << l << " " << r << " " << f[l] << endl;
        ans += f[l];
    }
    cout << ans << '\n';
}

void brute_force() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += a[j];
            if (sum > x) sum = 0;
            if (sum > 0) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    brute_force();
    return 0;
}
