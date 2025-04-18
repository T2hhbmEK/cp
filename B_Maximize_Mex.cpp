#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
// #define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int cnt[maxn];

void solve() {
    int n, x;
    cin >> n >> x;
    memset(cnt, 0, sizeof(int) * (n + 1));
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (a <= n) {
            ++cnt[a];
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (cnt[i] == 0) {
            cout << i << endl;
            return;
        }
        if (cnt[i] > 1) {
            if (i + x <= n) {
                cnt[i + x] += cnt[i] - 1;
            }
            cnt[i] = 1;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
