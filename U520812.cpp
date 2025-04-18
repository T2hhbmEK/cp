// Problem: U520812 E
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U520812?contestId=222025
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int INF = 0x3f3f3f3f;
const char ANY = '*';
using vi = vector<int>;
using vii = vector<vi>;
string f3(const string &s, int k) {
    int n = s.size();
    string r;
    r += s[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i - j < 0) break;
            if (s[i] == r[r.size() - j]) {
                for (int l = k; l >= j; --l) {
                    r += ANY;
                }
                break;
            }
        }
        r += s[i];
    }
    return r;
}

int f4(const string &s, const string &t) {
    int ans = INF;
    int n = s.size(), m = t.size();
    vii f(n + 1, vi(m + 1, 0));  // f[i][j]
    // find longest common substr
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            f[i][j] = max(f[i][j], f[i - 1][j - 1] + (s[i - 1] == t[j - 1]));
        }
    }
    // cout << f[n][m] << '\n';
    ans = n + m - f[n][m];
    return ans;
}

int f5(const string &S, const string &T, int k) {
    int ans = INF;
    string s = f3(S, k);
    string t = f3(T, k);
    int n = s.size(), m = t.size();
    // cout << s << endl;
    // cout << t << endl;
    vii f(n + 1, vi(m + 1, 0));  // f[i][j]
    // find longest common substr
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (s[i - 1] == t[j - 1]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            } else if (s[i - 1] == ANY) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            } else if (t[j - 1] == ANY) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
    }
    // cout << f[n][m] << '\n';
    ans = n + m - f[n][m];
    return ans;
}

int f7(const string &S, const string &T, int k) {
    int ans = INF;
    string s = f3(S, k);
    string t = f3(T, k);
    cout << s << endl;
    cout << t << endl;
    int n = s.size(), m = t.size();
    vii f(n + 1, vi(m + 1, 0));  // f[i][j]
    // find longest common substr
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else if (s[i - 1] == ANY) {
            } else if (t[j - 1] == ANY) {
            } else {
                f[i][j] = f[i - 1][j - 1] + 2;
            }
        }
    }
    // cout << f[n][m] << '\n';
    ans = f[n][m];
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    string s, t;
    cin >> n >> m >> k;
    cin >> s >> t;
    int ans = INF;
    if (s == t) {
        ans = f3(s, k).size();
    } else if (k == 0) {
        ans = f4(s, t);
    } else if (k == 1) {
        ans = f5(s, t, k);
    } else if (k == 2) {
        // ans = min(f7(s, t, k), f5(s, t, k));
        ans = f7(s, t, k);
    } else {
        ans = f7(s, t, k);
        // ans = min(f7(s, t, k), f5(s, t, k));
    }
    cout << ans << '\n';
    return 0;
}
