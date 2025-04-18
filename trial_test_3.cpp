#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1005
int n, a[N][N], dp_sum[N][N], dp_summx[N][N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            scanf("%d", &a[i][j]);
            dp_sum[i][j] = -1;
        }
    }
    for (int i = n, j = 1; j <= n; ++j) {
        dp_sum[i][j] = a[i][j];
        dp_summx[i][j] = a[i][j] * 2;
    }
    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            dp_sum[i][j] = max(dp_sum[i + 1][j], dp_sum[i + 1][j + 1]) + a[i][j];
            for (int k = j; k <= j + 1; ++k) {
                dp_summx[i][j] = max(dp_summx[i][j], dp_summx[i + 1][k] + a[i][j]);
                dp_summx[i][j] = max(dp_summx[i][j], dp_sum[i + 1][k] + 2 * a[i][j]);
            }
        }
    }
    cout << dp_summx[1][1] << endl;
    return 0;
}