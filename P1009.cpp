// Problem: P1009 [NOIP1998 普及组] 阶乘之和
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1009
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

// #define int long long
typedef long long LL;
const int MOD = 1e9;
const int MAXN = 1e3 + 5;

struct NUM {
    int a[MAXN];
    int k;

    void reset() {
        memset(a, 0, sizeof(a));
        k = 0;
    }

    NUM(const int& x = 0) {
        reset();
        a[0] = x;
    }

    void operator*=(const int& x) {
        if (x == 0) {
            reset();
            return;
        }
        for (int i = 0, t = 0; i <= k || t; ++i) {
            LL b = (LL)a[i] * x + t;
            a[i] = b % MOD;
            t = b / MOD;
            k = max(k, i);
        }
    }

    void operator+=(const NUM& x) {
        k = max(k, x.k);
        for (int i = 0, t = 0; i <= k || t; ++i) {
            LL b = (LL)a[i] + x.a[i] + t;
            a[i] = b % MOD;
            t = b / MOD;
            k = max(k, i);
        }
    }

    friend ostream& operator<<(ostream& os, const NUM& x) {
        os << x.a[x.k];
        for (int i = x.k - 1; i >= 0; --i) {
            os << setfill('0') << setw(9) << x.a[i];
        }
        return os;
    }
};

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    NUM a(1), ans(0);
    for (int i = 1; i <= n; ++i) {
        a *= i;
        ans += a;
    }
    cout << ans << '\n';
    return 0;
}
