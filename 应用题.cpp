#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define int long long

const int N = 1e6;
int n, m, ans, a[N][3];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int x = 0; x <= n; ++x) {
        int y = 5 * n - m - 4 * x;
        int z = m - 3 * n + 2 * x;
        if (y >= 0 && z >= 0 && y % 2 == 0 && z % 2 == 0) {
            y /= 2;
            z /= 2;
            a[ans][0] = x;
            a[ans][1] = y;
            a[ans][2] = z;
            ++ans;
        }
    }
    ans = ans == 0 ? -1 : ans;
    cout << ans << endl;
    for (int i = 0; i < ans; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
