#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n, d, head[N], nxt[N], to[N], cnt;
bool vis[N];
void add(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

int dfs(int u, int d) {
    if (vis[u]) {
        return 0;
    }
    int ans = 1;
    vis[u] = 1;
    if (d > 0) {
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            ans += dfs(v, d - 1);
        }
    }
    return ans;
}

int main() {
    cin >> n >> d;
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);  // undirected graph
    }
    cout << dfs(1, d) - 1 << endl;
    return 0;
}