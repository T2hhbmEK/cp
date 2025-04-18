#include <bits/stdc++.h>
using namespace std;
#define MaxN 105
#define MaxM 4505
int n, m, e[MaxN][MaxN];
void p() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", e[i][j]);
        }
        printf("\n");
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fill_n(e[i] + 1, n, 1e9);
        e[i][i] = 0;
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (w < e[v][u]) {
            e[u][v] = e[v][u] = w;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
    p();
    return 0;
}