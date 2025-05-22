#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e2 + 5;
const int MAXM = 2e5 + 5;

struct Edge {
    int u, v, w;
} e[MAXM];
bool vis[MAXN];
int n, m, k, ans;

bool cmp(Edge a, Edge b) { return a.w > b.w; }

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e + 1, e + m + 1, cmp);
    for (int i = 1; i <= k; ++i) {
        vis[e[i].u] = vis[e[i].v] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 1) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
