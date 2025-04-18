#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; 2 * i * i <= n; i += 2) {
        int a = n / (i * i);
        int cnt = -1;
        while (a) {
            a = a >> 1;
            cnt++;
        }
        // cout << i << " " << cnt << endl;
        ans += cnt;
    }
    cout << ans;
    return 0;
}
