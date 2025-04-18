#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> pa, sz;
    int cnt;
    explicit dsu(int n) : pa(n), sz(n, 1), cnt(n) {
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
        --cnt;
    }
};
struct edge {
    int x;
    int y;
    int l;
};
bool cmp(const edge &a, const edge &b) {
    return a.l < b.l;
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<edge> q;
    dsu u(n + 1);
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        q.push_back({x, y, l});
    }
    sort(q.begin(), q.end(), cmp);
    for (int i = 0; i < m && u.cnt > k + 1; ++i) {
        if (u.find(q[i].x) == u.find(q[i].y)) continue;
        u.unite(q[i].x, q[i].y);
        ans += q[i].l;
    }
    if (u.cnt == k + 1) {
        cout << ans << endl;
    } else {
        cout << "No Answer\n";
    }
    return 0;
}