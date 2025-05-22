// Problem: P1011 [NOIP1998 提高组] 车站
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1011
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 25;
int in[N], out[N], cnt[N];
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int a, n, m, x;
    cin >> a >> n >> m >> x;
    cnt[1] = cnt[2] = a;
    in[1] = a;
    for (int i = 0;; i++) {
        in[2] = out[2] = i;
        for (int j = 3; j <= n - 1; j++) {
            in[j] = in[j - 1] + in[j - 2];
            out[j] = in[j - 1];
            cnt[j] = cnt[j - 1] + in[j] - out[j];
        }
        if (cnt[n - 1] == m) {
            cout << cnt[x];
            return 0;
        }
    }
    cout << -1;
    return 0;
}