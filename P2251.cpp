#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LOGN 20
int n, m, a[LOGN][N], Log2[N];
void prep() {
    for (int i = 2; i <= n; ++i) Log2[i] = Log2[i >> 1] + 1;
}
void p() {
    for (int i = 0; 1 << i < m; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            printf("%-3d ", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P2251.in", "r", stdin);
#endif
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[0][i]);
    }
    prep();
    for (int i = 1; 1 << i < m; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            a[i][j] = min(a[i - 1][j], a[i - 1][j + (1 << i - 1)]);
            // printf("%d ", a[i][j]);
        }
        // printf("\n");
    }
    // p();
    for (int j = 1; j <= n - m + 1; ++j) {
        int i = Log2[m - 1];
        int q = min(a[i][j], a[i][j + m - (1 << i)]);
        printf("%d\n", q);
    }
    return 0;
}