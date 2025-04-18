#include <bits/stdc++.h>
using namespace std;
#define N 80005
#define LOGN 20
typedef long long ll;
int n, a[LOGN][N], lg2[N];
ll ans;
void ST() {
    for (int i = 2; i <= n; ++i) {
        lg2[i] = lg2[i >> 1] + 1;
    }
    for (int i = 1; i <= lg2[n - 1]; ++i) {
        for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
            a[i][j] = max(a[i - 1][j], a[i - 1][j + (1 << i - 1)]);
        }
    }
    // for (int i = 0; i <= lg2[n - 1]; ++i) {
    //     for (int j = 1; j + (1 << i) - 1 <= n; ++j) {
    //         printf("%-3d ", a[i][j]);
    //     }
    //     cout << endl;
    // }
}
int ST_max(int lhs, int rhs) {
    if (lhs > rhs) swap(lhs, rhs);
    int i = lg2[rhs - lhs];
    int ans = max(a[i][lhs], a[i][rhs - (1 << i) + 1]);
    return ans;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("P2866.in", "r", stdin);
#endif
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[0][i]);
    }
    ST();
    for (int i = 1; i <= n; ++i) {
        int j = i, j_rhs = n + 1;  // j -> [j, j_rhs)
        while (j + 1 < j_rhs) {
            int mid = (j + j_rhs) / 2;
            if (ST_max(i + 1, mid) < a[0][i]) {
                j = mid;
            } else {
                j_rhs = mid;
            }
        }
        // printf("%-3d ", j - i);
        ans += j - i;
    }
    cout << ans << endl;
    return 0;
}
