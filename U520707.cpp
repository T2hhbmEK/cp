// Problem: U520707 C
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U520707?contestId=222025
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 3e5 + 10;
struct T {
    int i;
    int c, x;
    int L, R;
} a[N];
int n, ans[N];
bool cmp(const T& x, const T& y) {
    if (x.x == y.x) return x.c < y.c;
    return x.x < y.x;
}
bool cmpi(const T& x, const T& y) {
    return x.i < y.i;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].c >> a[i].x;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    // for (int i = 1; i <= n; ++i) {
        // cout << a[i].c << ' ' << a[i].x << '\n';
    // }
    a[1].L = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i].c == a[i - 1].c) {
            a[i].L = a[i - 1].L;
        } else {
            a[i].L = i;
        }
    }
    a[n].R = n;
    for (int i = n - 1; i >= 1; --i) {
        if (a[i].c == a[i + 1].c) {
            a[i].R = a[i + 1].R;
        } else {
            a[i].R = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        int d = INF;
        vector<int> s = {a[i].L - 1, a[i].R + 1};
        for (int j : s) {
            // cout << j << " ";
            if (1 <= j && j <= n) {
                d = min(d, abs(a[j].x - a[i].x));
            }
        }
        ans[a[i].i] = d;
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}