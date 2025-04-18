// Problem: P1015 [NOIP1999 普及组] 回文数
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1015
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int MOD, M;
map<char, int> dct;
struct NUM {
    int a[MAXN];
    int k;
    void clear() {
        memset(a, 0, sizeof(a));
        k = 0;
    }
    NUM(string s) {
        clear();
        k = -1;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            a[++k] = dct[tolower(*it)];
        }
    }
    NUM(const NUM& x) {
        clear();
        k = x.k;
        for (int i = 0; i <= k; ++i) a[i] = x.a[i];
    }
    NUM reverse() {
        NUM x(*this);
        for (int i = 0, j = k; i < j; ++i, --j) {
            swap(x.a[i], x.a[j]);
        }
        return x;
    }
    void add(const NUM& x) {
        k = max(k, x.k);
        for (int i = 0, t = 0; i <= k || t; ++i) {
            a[i] += x.a[i] + t;
            t = a[i] / MOD;
            a[i] %= MOD;
            k = max(k, i);
        }
    }
    bool check() {
        for (int i = 0, j = k; i < j; ++i, --j) {
            if (a[i] != a[j]) return 0;
        }
        return 1;
    }
    void print() {
        for (int i = k; i >= 0; --i) {
            cout << "0123456789abcdef"[a[i]];
        }
    }
};
void init() {
    string t = "0123456789abcdef";
    for (int i = 0; i < (int)t.size(); i++) {
        dct[t[i]] = i;
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    init();
    cin >> MOD;
    string M;
    cin >> M;
    NUM a(M);
    int ans = 0;
    while (!a.check()) {
        if (++ans > 30) {
            cout << "Impossible!";
            return 0;
        }
        a.add(a.reverse());
        // a.print(), cout << '\n';
    }
    cout << "STEP=" << ans;
    return 0;
}