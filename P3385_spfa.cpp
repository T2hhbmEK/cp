#include <bits/stdc++.h>
using namespace std;
#define MaxN 2005
#define MaxM 6005  // 3000 * 2
int head[MaxN], nxt[MaxM], to[MaxM], wt[MaxM], en,
    dis[MaxN], cnt[MaxN];
bool vis[MaxN];

void add(int u, int v, int w) {
    nxt[++en] = head[u];
    head[u] = en;
    to[en] = v;
    wt[en] = w;
}

bool spfa(int s, int n, int m) {
    memset(dis + 1, 0x7f, sizeof(int) * n);  // 0x7f7f7f7f
    memset(vis + 1, 0, sizeof(int) * n);
    memset(cnt + 1, 0, sizeof(int) * n);
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;  // unique queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int j = head[u]; j; j = nxt[j]) {
            int v = to[j];
            int w = wt[j];
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) {
                    return true;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("P3385.in", "r", stdin);
#endif
    int t;
    cin >> t;
    for (int t_ = 1; t_ <= t; ++t_) {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(head + 1, 0, sizeof(int) * n);
        en = 0;
        for (int i = 1; i <= m; ++i) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (w >= 0) {
                add(u, v, w);
                add(v, u, w);
            } else {
                add(u, v, w);
            }
        }
        if (spfa(1, n, m)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}