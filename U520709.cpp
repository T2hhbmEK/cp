// Problem: U520709 D
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U520709?contestId=222025
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1.5e5 + 10;
int n, a[N], b[N];
LL ans;

int cnt(int x) {
    int a = 0;
    while (x) {
        x /= 10;
        a++;
    }
    return a;
}

int cap(int w) {
    int a = 1;
    while (w--) {
        a *= 10;
    }
    return a;
}

int main() {
    // cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        int w = cnt(x);
        int z = cap(w);
        int y1 = z - x;
        int y2 = x;  // a[i] >= b[?]
        int j1 = lower_bound(b + 1, b + 1 + n, y1) - b;
        j1--;
        int j2 = upper_bound(b + 1, b + 1 + n, y2) - b;
        j2--;
        j1 = min(j1, j2);
        ans += w * j1 + (w + 1) * (j2 - j1);
        // printf("%d %d %d\n", x, j1, j2);
    }
    // cout << ans << '\n';
    for (int i = 1; i <= n; ++i) {
        int x = b[i];
        int w = cnt(x);
        int z = cap(w);
        int y1 = z - x;
        int y2 = x - 1;  // b[i] > a[?]
        int j1 = lower_bound(a + 1, a + 1 + n, y1) - a;
        j1--;
        int j2 = upper_bound(a + 1, a + 1 + n, y2) - a;
        j2--;
        j1 = min(j1, j2);
        ans += w * j1 + (w + 1) * (j2 - j1);
        // printf("%d %d %d\n", x, j1, j2);
    }
    cout << ans << '\n';
    return 0;
}
