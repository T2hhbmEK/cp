#include <bits/stdc++.h>
#define int long long
#define maxn 1000005
using namespace std;

int n, ans;
const int m = 3;

bool chk(int x) {
    int s = x;
    while (x >= m) {
        s += x / m;
        x = x % m + x / m;
    }
    return s >= n;
}

signed main() {
    cin >> n;
    int L = 0, R = n;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        if (chk(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
