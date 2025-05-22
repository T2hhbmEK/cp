// hack 570 877
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define maxn 11
using namespace std;

int a, b, d, m, ok;
int tr[maxn];
int ans[maxn];

void dfs(int a, int b, int k) {
    if (k == 1) {
        if (b % a == 0 && (tr[k] = b / a) > tr[k + 1]) {
            ok = 1;
            if (tr[1] < ans[1]) memcpy(ans, tr, sizeof(tr));
        }
        return;
    }
    int g = __gcd(a, b);
    a /= g, b /= g;
    if (k == 2) {
        // a/b = x+y/xy
        // x+y = az -> z < 2m/z
        // xy = bz -> z < mm/b
        // x2-azx+bz=0
        // delta=(az)^2-4bz>0
        // z>4b/a^2
        // y<=1e7
        // x,y = az-+sqrt(delta) / 2
        int lo = (4 * b) / (a * a) + 1;
        int hi = min(2 * m / a, m * m / b);
        for (int z = lo; z < hi; z++) {
            int delta = a * z * a * z - 4 * b * z;
            int t = round(sqrt(delta));
            if (t * t != delta) continue;
            if ((a * z - t) % 2 != 0) continue;
            int x = (a * z - t) / 2;
            int y = (a * z + t) / 2;
            if (x <= tr[k + 1]) continue;
            if (y > 1e7) continue;
            tr[2] = x, tr[1] = y;
            if (tr[1] < ans[1]) memcpy(ans, tr, sizeof(tr));
            ok = 1;
        }
        return;
    }
    // a/b>1/i i>b/a
    int lo = max(b / a + 1, tr[k + 1] + 1);
    int hi = min(k * b / a - 1, m);  // a/b<k/i i<k*b/a
    if (ok) {
        hi = min(hi, ans[1] - 2);
    }
    for (int i = lo; i <= hi; i++) {
        // a/b-1/i = (a*i-b)/(b*i)
        tr[k] = i;
        dfs(a * i - b, b * i, k - 1);
    }
}

void prt(int tr[maxn]) {
    for (int i = d; i >= 1; i--) {
        cout << tr[i] << " ";
    }
    cout << endl;
}

int randint(int a, int b) {
    return rand() % (b - a) + a;
}

signed main() {
    memset(ans, inf, sizeof(ans));
    int a, b;
    cin >> a >> b;
    for (d = 1; d <= 10; d++) {
        for (m = 1000; m <= 1e7; m *= 10) {
            dfs(a, b, d);
            if (ok) {
                prt(ans);
                return 0;
            }
        }
    }
    return 0;
}
