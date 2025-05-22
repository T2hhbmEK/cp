#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int maxn = 1e6 + 5;

int b[maxn], c[maxn];

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int n2 = n * 2;
    for (int j = 0; j <= n2; ++j) {
        b[j] = n + 1;
        c[j] = -1;
    }
    b[n] = c[n] = 0;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'a') ++cnt;
        int j = cnt * 2 - i + n;
        b[j] = min(b[j], i);
        c[j] = max(c[j], i);
    }
    int ans = 0;
    for (int j = 0; j <= n2; ++j) {
        ans = max(ans, c[j] - b[j]);
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("sentence.in", "r", stdin);
    freopen("sentence.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
