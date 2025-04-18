#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> pa;
    vector<int> sz;
    int cnt;
    explicit dsu(int n) : pa(n), sz(n) {
    }
    void init() {
        iota(pa.begin(), pa.end(), 0);
        fill(sz.begin(), sz.end(), 1);
        cnt = 0;
    }
    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
        ++cnt;
    }
};
int main() {
#ifndef ONLINE_JUDGE
    freopen("P1536.in", "r", stdin);
#endif
    int nmax = 1005;
    dsu u(nmax);
    while (true) {
        int n, m;
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &m);
        u.init();
        for (int i = 1; i <= m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            u.unite(x, y);
        }
        printf("%d\n", n - 1 - u.cnt);
    }
    return 0;
}