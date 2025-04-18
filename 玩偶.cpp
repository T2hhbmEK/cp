#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

int n, m, ans;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int a = 0; 3 * a <= n; ++a) {
        for (int b = 0; 3 * a + 5 * b <= n; ++b) {
            int c = (n - 3 * a - 5 * b) * 3;
            if (a + b + c == m) {
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}
