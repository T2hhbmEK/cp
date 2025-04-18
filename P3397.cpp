#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n, m, a[N][N], t, l, b, r;
void p() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    // printf("\n");
}
void df() {
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            a[i][j] -= a[i - 1][j];
        }
    }
    for (int i = n; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            a[i][j] -= a[i][j - 1];
        }
    }
}
void ac() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] += a[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] += a[i - 1][j];
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &t, &l, &b, &r);
        // for (int i = t; i <= b; ++i) {
        //     for (int j = l; j <= r; ++j) {
        //         a[i][j] += 1;
        //     }
        // }
        a[t][l] += 1;
        a[b + 1][r + 1] += 1;
        a[t][r + 1] += -1;
        a[b + 1][l] += -1;
    }
    // p();
    // // df();
    // // p();
    ac();
    p();
    return 0;
}