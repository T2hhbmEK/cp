#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LOGN 20
int n, m, a[LOGN][N], logn[N];
void prep() {
    for (int i = 2; i <= n; ++i) {
        logn[i] = logn[i >> 1] + 1;
    }
}
int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') f = -1;
        c = getchar();
    }
    while ('0' <= c && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return f * x;
}
void p() {
    for (int i = 0; i <= logn[n - 1]; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P3865.in", "r", stdin);
#endif
    n = read(), m = read();
    prep();
    for (int i = 1; i <= n; ++i) a[0][i] = read();
    for (int i = 1; i <= logn[n - 1]; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << i - 1)]);
            // printf("[%d,%d]=max([%d,%d],[%d,%d])\n", j, j + (1 << i) - 1, j, j + (1 << i - 1) - 1, j + (1 << i - 1), j + (1 << i) - 1);
        }
    }
    // p();
    for (int k = 1; k <= m; ++k) {
        int l = read(), r = read();
        int i = logn[r - l];
        // printf("[%d,%d]=max([%d,%d],[%d,%d])\n", l, r, l, l + (1 << i) - 1, r - (1 << i) + 1, r);
        printf("%d\n", max(a[i][l], a[i][r - (1 << i) + 1]));
    }
    return 0;
}