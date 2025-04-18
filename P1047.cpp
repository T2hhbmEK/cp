#include <bits/stdc++.h>
using namespace std;
#define N 10005
int l, m, u, v, a[N], ans;
int main() {
    cin >> l >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        a[u] += 1;
        a[v + 1] -= 1;
    }
    ans += a[0] > 0 ? 0 : 1;
    for (int i = 1; i <= l; ++i) {
        a[i] += a[i - 1];
        ans += a[i] > 0 ? 0 : 1;
    }
    cout << ans << endl;
    return 0;
}