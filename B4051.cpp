#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;

int n, m;
int c[N], a[N];
int cmax = -INF;
int sum, psum, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        cmax = max(cmax, c[i]);
    }
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        sum += a[i];
        if (a[i] > 0) psum += a[i];
    }
    if (n == 1) {
        ans = cmax + sum;
    } else {
        ans = cmax + psum;
    }
    cout << ans;
    return 0;
}
