#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 200005

int n, m, s, u, v, w, dis[N];
int nxt[M], head[M], to[M], wt[M], cnt;
bool vis[N];
void add(int u, int v, int w) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    wt[cnt] = w;
};
struct Node {
    int u;
    int d;
    bool operator<(const Node &y) const {
        return d > y.d;
    }
};
priority_queue<Node> q;

void dijkstra() {
    fill_n(dis + 1, n, INT_MAX);
    dis[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        u = q.top().u;
        q.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (int i = head[u]; i; i = nxt[i]) {
                v = to[i];
                w = wt[i];
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push({v, dis[v]});
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra();
    for (int u = 1; u <= n; ++u) {
        printf("%d ", dis[u]);
    }
    printf("\n");
    return 0;
}