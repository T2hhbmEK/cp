#include <bits/stdc++.h>
#define print(...) cout << format(__VA_ARGS__)
#define println(...) cout << format(__VA_ARGS__) << '\n'
#define MAXN 128
#define INF 0x3f3f3f3f
using namespace std;
using pii = pair<int, int>;
int N, K, M, S, T;
int C[MAXN];
vector<int> a[MAXN];  // a[j][i] i excluse j, j exclused by a[j]
unordered_map<int, int> e[MAXN];
int dis[MAXN], vis[MAXN];
int ans = INF, sum = 0;
void dijkstra() {
  memset(dis, INF, sizeof(dis));
  priority_queue<pii, vector<pii>, greater<>> q;
  dis[T] = 0;
  q.emplace(0, T);
  while (!q.empty()) {
    int u = q.top().second;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto& [v, d] : e[u]) {
      if (dis[u] + d < dis[v]) {
        dis[v] = dis[u] + d;
        q.emplace(dis[v], v);
      }
    }
  }
}
void dfs(int u) {
  if (vis[C[u]] > 0) return;
  if (sum + dis[u] >= ans) return;
  if (u == T) {
    ans = min(ans, sum);
    return;
  }
  for (auto& x : a[C[u]]) vis[x] += 1;
  for (const auto& [v, d] : e[u]) {
    sum += d;
    dfs(v);
    sum -= d;
  }
  for (auto& x : a[C[u]]) vis[x] -= 1;
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  cin >> N >> K >> M >> S >> T;
  for (int i = 1; i <= N; ++i) cin >> C[i];
  for (int i = 1; i <= K; ++i) {
    for (int j = 1, x; j <= K; ++j) {
      cin >> x;
      if (x == 1 || i == j) a[j].push_back(i);
    }
  }
  for (int i = 1; i <= M; ++i) {
    int u, v, d;
    cin >> u >> v >> d;
    e[u][v] = e[u].contains(v) ? min(e[u][v], d) : d;
    e[v][u] = e[u][v];
  }
  dijkstra();
  if (dis[S] == INF) {
    println("{}", -1);
    return 0;
  }
  memset(vis, 0, sizeof(vis));
  dfs(S);
  println("{}", ans == INF ? -1 : ans);
  return 0;
}
