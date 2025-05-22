#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 25, maxf = 125;

int s[5], n, sum, a[maxn], f[maxf], ans;

int solve(int n) {
    sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for (int i = 1; i <= n; i++) {
        memset(f, 0, sizeof(f));
        for (int j = sum >> 1; j >= a[i]; j--) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }
    cout << f[sum >> 1] << endl;
    return sum - f[sum >> 1];
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= 4; i++) cin >> s[i];
    for (int i = 1; i <= 4; i++) {
        ans += solve(s[i]);
    }
    cout << ans;
    return 0;
}
