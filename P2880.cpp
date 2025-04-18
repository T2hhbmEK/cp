#include <bits/stdc++.h>
using namespace std;
#define N 50005
#define LOGN 20
int n, q, hmax[N][LOGN], hmin[N][LOGN], LOG2[N];
int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return f * x;
}
void st() {
    for (int i = 2; i <= n; ++i) {
        LOG2[i] = LOG2[i >> 1] + 1;
    }
    for (int j = 1; j <= LOG2[n - 1]; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            hmax[i][j] = max(hmax[i][j - 1], hmax[i + (1 << j - 1)][j - 1]);
            hmin[i][j] = min(hmin[i][j - 1], hmin[i + (1 << j - 1)][j - 1]);
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P2880.in", "r", stdin);
#endif
    n = read(), q = read();
    for (int i = 1; i <= n; ++i) {
        hmax[i][0] = hmin[i][0] = read();
    }
    st();
    for (int i = 1; i <= q; ++i) {
        int a = read(), b = read();
        int j = LOG2[b - a];
        int m1 = min(hmin[a][j], hmin[b - (1 << j) + 1][j]);
        int m2 = max(hmax[a][j], hmax[b - (1 << j) + 1][j]);
        printf("%d\n", m2 - m1);
    }
    return 0;
}