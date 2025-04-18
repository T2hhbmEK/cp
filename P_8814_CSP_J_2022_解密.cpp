#include <bits/stdc++.h>
using namespace std;

#define int long long

int bs(int n, int m) {
    int l = 1, r = m >> 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (mid * (m - mid) == n) {
            return mid;
        } else if (mid * (m - mid) < n) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int k;
    cin >> k;
    while (k--) {
        int n, e, d;
        cin >> n >> e >> d;
        int m = n - e * d + 2;  // p + q = m, p * q = n, p <= q
        int p = bs(n, m);
        if (p == -1) {
            cout << "NO" << endl;
        } else {
            cout << p << " " << m - p << endl;
        }
    }
    return 0;
}
