#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e5 + 5;
const int MAXH = 1e4;
int n, k;
int h[MAXN], w[MAXN];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (h[i] / x) * (w[i] / x);
    return cnt >= k;
}

void solve() {
    int l = 1, r = MAXH;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
}

void bf() {
    for (int i = 1; i <= MAXH; i++) {
        if (!check(i)) {
            cout << i - 1 << endl;
            return;
        }
    }
}

signed main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> h[i] >> w[i];
    bf();
    return 0;
}
