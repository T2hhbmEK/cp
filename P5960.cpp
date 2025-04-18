#include <bits/stdc++.h>
using namespace std;
#define N 50010 // additional source vertax
bool vis[N];
int n, m, en, dis[N], cnt[N], head[N], nxt[N], to[N], wt[N];
void add(int u, int v, int w) {
    nxt[++en] = head[u];
    head[u] = en;
    to[en] = v;
    wt[en] = w;
}
queue<int> q;
bool spfa(int s, int n) {
    memset(dis, 0x7f, sizeof(dis));
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            int w = wt[i];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    return false;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P5960.in", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &v, &u, &w);  // d[v] <= d[u] + w(u->v)
        add(u, v, w);
    }
    for (int i = 1; i <= n; ++i) {
        add(n + 1, i, 0);
    }
    if (spfa(n + 1, n + 1)) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", dis[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }
    return 0;
}