#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define int long long
const int mod = 1e9;
int a[128];
string s;
int g(int k) {
    if (isdigit(s[k])) return s[k] - '0';
    return a[s[k]];
}
void f(int k) {
    // cout << s.substr(k) << endl;
    if (k >= s.size()) return;
    if (s[k] == 'f') {  // for
        char c = s[k + 4];
        int l = g(k + 6);
        int r = g(k + 8);
        while (r < l) r += mod;
        for (int i = l; i <= r; i++) {
            a[c] = i;
            if (a[c] >= 2 * mod) {
                a[c] = a[c] % mod + mod;
            }
            f(k + 10);
        }
        return;
    }
    if (isupper(s[k])) {
        char c = s[k];
        if (s[k + 1] == '=') {  // =
            a[c] = g(k + 2);
        } else if (s[k + 1] == '+') {  // +=
            a[c] += g(k + 3);
            if (a[c] >= 2 * mod) {
                a[c] = a[c] % mod + mod;
            }
        }
        return;
    }
}
signed main() {
    freopen("evaluation.in", "r", stdin);
    freopen("evaluation.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    while (getline(cin, s)) {
        f(0);
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (a[c] >= mod) {
            printf("%c=...%09d\n", c, a[c] % mod);
        } else if (a[c]) {
            printf("%c=%d\n", c, a[c]);
        }
        // printf("%c=%d\n", c, a[c]);
    }
    return 0;
}
