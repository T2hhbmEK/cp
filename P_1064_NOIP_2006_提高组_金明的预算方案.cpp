#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 3.4e4 + 5, maxm = 65;
int n, m, v[maxm], p[maxm], q;
vector<int> ch[maxm];
vector<int> a;
int f[maxn];

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> p[i] >> q;
        if (q) {
            ch[q].push_back(i);
        } else {
            a.push_back(i);
        }
    }
    for (auto& i : a) {
        ch[i].resize(2);
        int c0 = ch[i][0], c1 = ch[i][1];
        for (int j = n; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + v[i] * p[i]);
            if (j >= v[i] + v[c0])
                f[j] = max(f[j],
                           f[j - v[i] - v[c0]] + v[i] * p[i] + v[c0] * p[c0]);
            if (j >= v[i] + v[c1])
                f[j] = max(f[j],
                           f[j - v[i] - v[c1]] + v[i] * p[i] + v[c1] * p[c1]);
            if (j >= v[i] + v[c0] + v[c1])
                f[j] = max(f[j], f[j - v[i] - v[c0] - v[c1]] + v[i] * p[i] +
                                     v[c0] * p[c0] + v[c1] * p[c1]);
        }
    }
    cout << f[n];
    return 0;
}
