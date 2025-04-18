#include <bits/stdc++.h>
using namespace std;
#define N 10
int n, m, t, sx, sy, tx, ty, mz[N][N], ans[N][N], flag[N][N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void _print(int mz[N][N]) {
    for (int y = 0; y <= m + 1; ++y) {
        for (int x = 0; x <= n + 1; ++x) {
            printf("%d ", mz[y][x]);
        }
        printf("\n");
    }
}
void dfs(int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (flag[y1][x1] == 0 && mz[y1][x1] == 0) {
            flag[y1][x1] = 1;
            ans[y1][x1] += 1;
            dfs(x1, y1);
            flag[y1][x1] = 0;
        }
    }
}
int main() {
    cin >> n >> m >> t;
    cin >> sx >> sy >> tx >> ty;
    for (int i = 0; i < t; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        mz[y][x] = 1;
    }
    for (int i = 0; i <= m + 1; ++i) {
        mz[i][0] = 1;
        mz[i][n + 1] = 1;
    }
    for (int j = 0; j <= n + 1; ++j) {
        mz[0][j] = 1;
        mz[m + 1][j] = 1;
    }
    // _print(mz);
    flag[sy][sx] = 1;
    ans[sy][sx] = 1;
    dfs(sx, sy);
    // _print(ans);
    cout << ans[ty][tx] << endl;
    return 0;
}