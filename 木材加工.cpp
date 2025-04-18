#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e6 + 5;

int n, k, a[maxn];

bool check(int l) {
    int m = 0;
    for (int i = 1; i <= n; i++) {
        m += a[i] / l;
    }
    return m >= k;
}

signed main() {
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int l = 1, r = sum / k;
    if (r == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << endl;
}
