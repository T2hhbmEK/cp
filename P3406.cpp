#include <bits/stdc++.h>
using namespace std;
#define N 100'005
int n, m, p[N], a[N], b[N], c[N];
long long ans, d[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d", p + i);
    }
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d%d%d", a + i, b + i, c + i);
    }
    for (int i = 1; i < m; ++i) {
        int l = p[i - 1], r = p[i];
        if (l > r) {
            swap(l, r);
        }
        d[l] += 1;
        d[r] -= 1;
    }
    for (int i = 1; i <= n; ++i) {
        d[i] += d[i - 1];
        ans += min(d[i] * a[i], c[i] + d[i] * b[i]);
    }
    cout << ans << endl;
    return 0;
}