#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> pa, sz;
    explicit dsu(int n) : pa(n), sz(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
    }
    int size(int x) { return sz[find(x)]; }
};
int main() {
    int n, m, p, q;
    cin >> n >> m >> p >> q;
    dsu a(n + 1), b(m + 1);
    for (int i = 1; i <= p; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        a.unite(x, y);
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        b.unite(-x, -y);
    }
    cout << min(a.size(1), b.size(1)) << endl;
    return 0;
}