#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;

int n, m;
int a[maxn], b;
long long ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> a[i];
    sort(a + 1, a + m + 1);
    m = unique(a + 1, a + m + 1) - (a + 1);
    a[0] = -inf, a[m + 1] = inf;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        int l = lower_bound(a + 1, a + m + 1, b) - a;
        ans += min(abs(a[l - 1] - b), abs(a[l] - b));
    }
    cout << ans << '\n';
}
