#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9 + 7;
const int LINF = 1e18 + 7;
const int N = 1e4 + 7;
int n, m, u, v, w;
int head[N], nxt[N], to[N], wt[N], cnt;
void add(int u, int v, int w) {
    cnt += 1;
    nxt[cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
    wt[cnt] = w;
}
int sum, smin = INF;
void dfs(int u) {
    if (u == n) {
        if (sum < smin) smin = sum;
        return;
    }
    if (sum >= smin) {
        return;
    }
    for (int i = head[u]; i; i = nxt[i]) {
        v = to[i];
        sum += wt[i];
        // cout << u << "->" << v << " " << sum << endl;
        dfs(v);
        sum -= wt[i];
    }
}
int main() {
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        add(u, v, w);
    }
    dfs(1);
    cout << smin;
    return 0;
}