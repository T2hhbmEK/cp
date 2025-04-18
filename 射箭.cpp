#include <bits/stdc++.h>
using namespace std;

int n, x, ans;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for (int i = 0; i <= n && 3 * i <= x; i++) {
        int j = x - 3 * i;
        if (j % 2 == 0 && i + j / 2 <= n) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
