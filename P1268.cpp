#include <bits/stdc++.h>
using namespace std;
#define N 50
int n, d[N][N], ans;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%d", &d[i][j]);
            d[j][i] = d[i][j];
        }
    }
    ans = d[1][2];
    for (int i = 3; i <= n; ++i) {
        int len = INT_MAX;
        for (int j = 2; j < i; ++j) {
            len = min(len, (d[1][i] + d[j][i] - d[1][j]) / 2);
        }
        ans += len;
    }
    cout << ans << endl;
    return 0;
}