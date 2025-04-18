#include <bits/stdc++.h>
using namespace std;

const int N = 100;
const int MOD = 1e4;
int n, m, a[N][N];
struct NUM {
    int a[50];
    int k;
    void clear() {
        memset(a, 0, sizeof(a));
        k = 0;
    }
    NUM() {
        clear();
    }
    NUM(const NUM& x) {
        *this = x;
    }
    NUM(const int& x) {
        *this = x;
    }
    NUM& operator=(const NUM& x) {
        clear();
        memcpy(a, x.a, sizeof(a));
        k = x.k;
        return *this;
    }
    NUM& operator=(const int& x) {
        clear();
        *this += x;
        return *this;
    }
    NUM& operator+=(const int& x) {
        for (int i = 0, t = x; i <= k || t > 0; i++) {
            t += a[i];
            a[i] = t % MOD;
            t /= MOD;
            k = max(k, i);
        }
        return *this;
    }
    friend NUM operator+(const NUM& x, const int& y) {
        NUM z = x;
        z += y;
        return z;
    }
    friend NUM operator+(const int x, const NUM& y) {
        return y + x;
    }
    NUM& operator*=(const int& x) {
        for (int i = 0, t = 0; i <= k || t > 0; i++) {
            a[i] = a[i] * x + t;
            t = a[i] / MOD;
            a[i] %= MOD;
            k = max(k, i);
        }
        return *this;
    }
    friend NUM operator*(const NUM& x, const int& y) {
        NUM z = x;
        z *= y;
        return z;
    }
    friend NUM operator*(const int x, const NUM& y) {
        return y * x;
    }
    NUM& operator+=(const NUM& x) {
        k = max(k, x.k);
        for (int i = 0, t = 0; i <= k || t > 0; i++) {
            a[i] += (i <= x.k ? x.a[i] : 0) + t;
            t = a[i] / MOD;
            a[i] %= MOD;
            k = max(k, i);
        }
        return *this;
    }
    friend NUM operator+(const NUM& x, const NUM& y) {
        NUM z = x;
        z += y;
        return z;
    }
    friend ostream& operator<<(ostream& os, const NUM& x) {
        cout << x.a[x.k];
        for (int i = x.k - 1; i >= 0; i--) {
            cout << setw((int)log10(MOD)) << setfill('0') << x.a[i];
        }
        return os;
    }
    friend bool operator<(const NUM& x, const NUM& y) {
        if (x.k != y.k) return x.k < y.k;
        for (int i = x.k; i >= 0; i--) {
            if (x.a[i] != y.a[i]) return x.a[i] < y.a[i];
        }
        return false;
    }
} ans, f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (auto& x : f) x.clear();
        for (int len = 1; len <= m; len++) {
            for (int j = 1; j + len - 1 <= m; j++) {
                NUM L = a[i][j] + f[j + 1];
                NUM R = f[j] + a[i][j + len - 1];
                f[j] = max(L * 2, R * 2);
            }
        }
        ans += f[1];
    }
    cout << ans;
    return 0;
}
