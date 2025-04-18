#include <bits/stdc++.h>
using namespace std;
#define N 5000'005
int n, p, a[N], x, y, z;
int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = n; i >= 1; --i) {
        a[i] -= a[i - 1];
    }
    for (int i = 1; i <= p; ++i) {
        scanf("%d%d%d", &x, &y, &z);
        a[x] += z;
        a[y + 1] -= z;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
        ans = min(ans, a[i]);
    }
    cout << ans << endl;
    return 0;
}