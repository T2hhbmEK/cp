#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;

const int maxn = 105;
const int maxm = 10005;
int m, n, a[maxn], f[maxm];

signed main() {
    scanf("%lld%lld", &n, &m);
    rep(i, 1, n) scanf("%lld", &a[i]);
    f[0] = 1;
    rep(i, 1, n) per(j, m, a[i]) {
        f[j] += f[j - a[i]];
    }
    printf("%lld", f[m]);
    return 0;
}
