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
    int nxt;
    int v;
};
struct graph {
    vector<int> head;
    vector<edge> e;
    int cnt;
    explicit graph(int n) : cnt(-1), head(n, -1) {}
    void add_(int u, int v) {
        e.push_back({head[u], v});
        head[u] = ++cnt;
    }
    void add(int u, int v) {
        add_(u, v), add_(v, u);
    }
};
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    dsu uu(n + 1);
    graph g(n + 1);
    for (int i = 1; i <= m; ++i) {
        char op[2];
        int p, q;
        scanf("%s%d%d", op, &p, &q);
        switch (op[0]) {
            case 'F':
                uu.unite(p, q);
                break;
            case 'E':
                g.add(p, q);
                break;
            default:
                cout << op << endl;
                assert(false);
        }
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = g.head[u]; ~i; i = g.e[i].nxt) {
            int v = g.e[i].v;  // E
            for (int j = g.head[v]; ~j; j = g.e[j].nxt) {
                int w = g.e[j].v;  // F
                if (w == u || uu.find(u) == uu.find(w)) continue;
                uu.unite(u, w);
            }
        }
    }
    cout << uu.cnt - 1 << endl;
    return 0;
}