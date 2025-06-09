#include <bits/stdc++.h>
#define int long long
#define maxn 200010
using namespace std;

int n, b[maxn], ci, ans;

signed main() {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> b[i];
    for (int i = 1; i <= 2 * n; i++) cin >> ci, ans += ci, b[i] -= ci;
    sort(b + 1, b + 1 + 2 * n, greater<int>());
    for (int i = 1; i <= n; i++) ans += b[i];
    cout << ans << '\n';
    return 0;
}
