#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define LOGN 20
int n, a[LOGN][N], b[N], lg2[N];
void buildST() {
    for (int i = 2; i <= n; ++i) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= lg2[n - 1]; ++i) {
        for (int j = 0; j < n; ++j) {
            a[i][j] = max(a[i - 1][j], a[i - 1][(j + (1 << i - 1)) % n]);
        }
    }
    // for (int j = 0; j < n; ++j) {
    //     printf("%-3d ", b[j]);
    // }
    // putchar('\n');
    // for (int i = 0; i <= lg2[n - 1]; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         printf("%-3d ", a[i][j]);
    //     }
    //     putchar('\n');
    // }
}
int maxST(int lhs, int rhs) {
    if (lhs > rhs) swap(lhs, rhs);
    assert(rhs - lhs <= n - 1);
    int i = lg2[rhs - lhs];
    int ans = max(a[i][lhs % n], a[i][(rhs - (1 << i) + 1) % n]);
    // printf("maxST(%d,%d)=%d\n", lhs, rhs, ans);
    return ans;
}
int find_right(int i) {
    assert(i >= 0 && i < n);
    int lhs = i, rhs = i + n - 1;  // (lhs, rhs]
    while (lhs + 1 < rhs) {
        int mid = (lhs + rhs) / 2;
        if (maxST(i + 1, mid) >= b[i]) {
            rhs = mid;
        } else {
            lhs = mid;
        }
        // printf("(%d,%d]\n", lhs, rhs);
    }
    int j = rhs;
    if (a[0][j % n] >= b[i]) {
        return j - i;
    } else {
        return -1;
    }
}
int find_left(int i) {
    assert(i >= n && i < 2 * n);
    int lhs = i - n + 1, rhs = i;  // [lhs, rhs)
    assert(lhs >= 0);
    while (lhs + 1 < rhs) {
        int mid = (lhs + rhs) / 2;
        if (maxST(mid, i - 1) >= b[i % n]) {
            lhs = mid;
        } else {
            rhs = mid;
        }
        // printf("[%d,%d)\n", lhs, rhs);
    }
    int j = lhs;
    // printf("i=%d,j=%d\n", i, j);
    if (a[0][j % n] >= b[i % n]) {
        return i - j;
    } else {
        return -1;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P7333.in", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[0][i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    buildST();
    for (int i = 0; i < n; ++i) {
        int f = -1;
        int f_right = find_right(i);
        if (f_right > 0) f = f_right;
        int f_left = find_left(i + n);
        if (f_left > 0) f = min(f, f_left);
        printf("%d ", f);
    }
    printf("\n");
    return 0;
}