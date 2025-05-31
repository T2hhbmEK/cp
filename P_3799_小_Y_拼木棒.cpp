#include <bits/stdc++.h>
#define int long long
#define maxm 5000
#define mod 1'000'000'007
using namespace std;

int n, x, cnt[maxm + 1], ans;

int comb(int n, int m) {
    int r = 1;
    if (m > n) return 0;
    if (m > (n >> 1)) m = n - m;
    for (int i = 0; i < m; i++) r *= n - i;
    for (int i = 1; i <= m; i++) r /= i;
    return r;
}

signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= maxm; i++) {
        if (cnt[i] < 2) continue;
        int j;
        for (j = 1; j < i - j; j++) {
            ans += cnt[j] * cnt[i - j] % mod * comb(cnt[i], 2) % mod;
        }
        if (j + j == i) {
            ans += comb(cnt[j], 2) * comb(cnt[i], 2) % mod;
        }
        ans %= mod;
    }
    cout << ans;
    return 0;
}
