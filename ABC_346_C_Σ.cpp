#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;
int n, k, a[maxn];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = (k + 1) * k / 2;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) continue;
        if (a[i] > k) break;
        ans -= a[i];
    }
    cout << ans << endl;
    return 0;
}
