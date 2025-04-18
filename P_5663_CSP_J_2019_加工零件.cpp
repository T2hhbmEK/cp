#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<vector<int>> edges;
vector<vector<int>> dis;

void prt_dis() {
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i <= n; i++) {
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int u, int d) {
    d++;
    for (auto v : edges[u]) {
        if (d < dis[v][d & 1]) {
            dis[v][d & 1] = d;
            dfs(v, d);
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> q;
    edges.resize(n + 1);
    dis.resize(n + 1, vector<int>(2, 0x3f3f3f3f));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 0; i < q; i++) {
        int a, l;
        cin >> a >> l;
        if (dis[a][l & 1] > l) {
            cout << "No" << '\n';
        } else {
            l -= dis[a][l & 1];
            cout << (l & 1 ? "No" : "Yes") << '\n';
        }
    }
    return 0;
}
