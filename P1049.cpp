#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
using ll = long long;

const int maxn = 35;
const int maxv = 20005;
int V, n, a[maxn], f[maxv];

signed main() {
    scanf("%lld%lld", &V, &n);
    rep(i, 1, n) scanf("%lld", &a[i]);
    rep(i, 1, n) per(j, V, 0) {
        if (j >= a[i]) {
            f[j] = max(f[j - a[i]] + a[i], f[j]);
        }
    }
    printf("%lld", V - f[V]);
    return 0;
}
