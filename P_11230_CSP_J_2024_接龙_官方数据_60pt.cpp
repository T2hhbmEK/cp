#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

ll cnt;
ll maxn;

void clear(vii &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        a[i].assign(a[i].size(), 0);
    }
}

void presum(vii &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 1; j < (int)a[i].size(); j++) {
            a[i][j] += a[i][j - 1];
        }
    }
}

void setf(vii &s, vii &df, unordered_map<int, unordered_set<int>> &fi) {
    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)s[i].size(); j++) {
            if (df[i][j] > 0 && fi[s[i][j]].size() < 2) {
                fi[s[i][j]].insert(i);
            }
        }
    }
}

void prt(vii &a) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[i].size(); j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vii s(n);
    unordered_map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        maxn += l;
        s[i].resize(l, 0);
        for (int j = 0; j < l; j++) {
            cin >> s[i][j];
            mp[s[i][j]].push_back({i, j});
        }
    }
    vector<pair<int, int>> query(q);
    int maxr = 0;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        query[i] = {r, c};
        maxr = max(maxr, r);
    }
    vector<unordered_map<int, unordered_set<int>>> f(maxr + 1);
    vii df;
    for (int i = 0; i < n; i++) {
        df.emplace_back(vi(s[i].size(), 0));
    }
    for (auto &p : mp[1]) {
        int i = p.first, j = p.second;
        int l = df[i].size();
        if (j + 1 < l) df[i][j + 1] += 1;
        if (j + k < l) df[i][j + k] -= 1;
    }
    presum(df);
    setf(s, df, f[1]);
    for (int r = 2; r <= maxr; r++) {
        clear(df);
        for (auto &p : f[r - 1]) {
            int a = p.first;
            int b = -1;
            if (p.second.size() == 1) {
                for (auto &x : p.second) b = x;
            }
            for (auto &p2 : mp[a]) {
                cnt++;
                int i = p2.first, j = p2.second;
                if (i == b) continue;
                int l = df[i].size();
                if (j + 1 < l) df[i][j + 1] += 1;
                if (j + k < l) df[i][j + k] -= 1;
            }
        }
        presum(df);
        setf(s, df, f[r]);
    }
    for (int i = 0; i < q; i++) {
        int r = query[i].first;
        int c = query[i].second;
        bool ok = f[r].find(c) != f[r].end() && f[r][c].size() > 0;
        cout << ok << endl;
    }
}

int main() {
    // freopen("./chain/chain6.in", "r", stdin);
    // freopen("./chain/chain6.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    // cerr << maxn << endl;
    // cerr << cnt << endl;
    return 0;
}
