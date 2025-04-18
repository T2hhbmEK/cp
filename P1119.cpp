#include <bits/stdc++.h>
using namespace std;
#define MaxN 205
#define MaxM 20005
int n, m, t[MaxN], qn;
int dp[MaxN][MaxN];
void p() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
}
int main() {
    // freopen("P1119.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        fill_n(dp[i], n, INT_MAX);
        dp[i][i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dp[u][v] = w;
        dp[v][u] = w;
    }
    cin >> qn;
    int k = 0;
    for (int i = 0; i < qn; ++i) {
        int x, y, t_;
        scanf("%d%d%d", &x, &y, &t_);
        while (k < n && t[k] <= t_) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    if (dp[u][k] != INT_MAX && dp[k][v] != INT_MAX) {
                        dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);
                    }
                }
            }
            k++;
        }
        if (x < k && y < k && dp[x][y] != INT_MAX) {
            printf("%d\n", dp[x][y]);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}