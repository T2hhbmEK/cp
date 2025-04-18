#include <bits/stdc++.h>
using namespace std;
struct dsu {
    vector<int> pa;
    vector<int> size;
    explicit dsu(int n) : pa(n * 2), size(n * 2, 1) {
        iota(pa.begin(), pa.begin() + n, n);
        iota(pa.begin() + n, pa.end(), n);
    }
    int find(int x) {
        return x == pa[x] ? x : pa[x] = find(pa[x]);
    }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        if (size[x] < size[y]) swap(x, y);
        pa[y] = x;
        size[x] += size[y];
    }
};
int main() {
    int n, m, p;
    cin >> n >> m >> p;
    dsu u(n + 1);
    for (int i = 0; i < m; ++i) {
        int mi, mj;
        scanf("%d%d", &mi, &mj);
        u.unite(mi, mj);
    }
    for (int i = 0; i < p; ++i) {
        int pi, pj;
        scanf("%d%d", &pi, &pj);
        printf(u.find(pi) == u.find(pj) ? "Yes\n" : "No\n");
    }
    return 0;
}