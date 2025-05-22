#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, l, r;
int a[maxn];
int f[maxn];
int q[maxn], L, R;
int ans = -0x3f3f3f3f;

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) cin >> a[i];
    memset(f, -0x3f, sizeof(f));
    f[0] = 0;
    for (int i = l; i <= n; i++) {  // [i-r, i-l] -> i
        while (L <= R && q[L] < i - r) L++;
        while (L <= R && f[q[R]] < f[i - l]) R--;
        q[++R] = i - l;
        f[i] = f[q[L]] + a[i];
    }
    // for (int i = 0; i <= n; i++) cout << f[i] << " \n"[i == n];
    for (int i = n + 1 - r; i <= n; i++) ans = max(ans, f[i]);
    cout << ans;
    return 0;
}
