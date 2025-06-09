#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

struct Bigint {
    int a[maxn], n;
    Bigint(int x = 0) {
        *this = x;
    }
    Bigint& operator=(int x) {
        memset(a, 0, sizeof(a));
        n = 0;
        while (x) {
            a[++n] = x % 10;
            x /= 10;
        }
        return *this;
    }
    Bigint& operator=(Bigint other) {
        memcpy(a, other.a, sizeof(a));
        n = other.n;
        return *this;
    }
    void flatten() {
        for (int i = 1; i <= n; ++i) {
            a[i + 1] += a[i] / 10;
            a[i] %= 10;
            if (a[i + 1]) n = max(n, i + 1);
        }
        while (n > 0 && a[n] == 0) --n;
    }
    Bigint operator+(Bigint other) {
        Bigint ans = 0;
        ans.n = max(n, other.n);
        for (int i = 1; i <= ans.n; ++i) {
            ans.a[i] = a[i] + other.a[i];
        }
        ans.flatten();
        return ans;
    }
    friend ostream& operator<<(ostream& os, Bigint x) {
        if (x.n == 0) return os << 0;
        for (int i = x.n; i >= 1; --i) {
            os << x.a[i];
        }
        return os;
    }
};

int m, n;
Bigint f[maxn];

signed main() {
    cin >> m >> n;
    f[m] = 1;
    for (int i = m + 1; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];
        // cout << i << " " << f[i - 1] << " " << f[i - 2] << " " << f[i] <<
        // endl;
    }
    cout << f[n] << endl;
    return 0;
}
