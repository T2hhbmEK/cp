#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int maxa, n, k, a[maxn];

bool check(int d) {
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        cnt += (a[i] - a[i - 1] - 1) / d;
    }
    return cnt <= k;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> maxa >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (k + n >= maxa + 1) {
        cout << 1 << endl;
        return 0;
    }
    int l = 1, r = maxa;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
