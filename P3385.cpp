#include <bits/stdc++.h>
using namespace std;
#define MaxN 2005
#define MaxM 6005
typedef long long ll;
int head[MaxN], nxt[MaxM], to[MaxM], wt[MaxM], cnt;
ll dis[MaxN];

void add(int u, int v, int w) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    wt[cnt] = w;
}

bool bellmanford(int s, int n, int m) {
    // fill_n(dis + 1, n, INT_MAX);
    memset(dis, 0x7f, sizeof(dis));
    dis[s] = 0;
    bool upd = false;
    for (int i = 1; i <= n; ++i) {
        upd = false;
        for (int u = 1; u <= n; ++u) {
            if (dis[u] != 0x7f7f7f7f7f7f7f7f) {
                for (int j = head[u]; j; j = nxt[j]) {
                    int v = to[j];
                    int w = wt[j];
                    if (dis[v] > dis[u] + w) {
                        dis[v] = dis[u] + w;
                        upd = true;
                    }
                }
            }
        }
        if (!upd) {
            break;
        }
    }
    return upd;
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
        memset(head, 0, sizeof(head));
        cnt = 0;
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
        if (bellmanford(1, n, m)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}