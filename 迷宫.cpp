#include <bits/stdc++.h>
using namespace std;
const int NMAX = 15;
int n, m, t, sx, sy, ex, ey;
int mz[NMAX][NMAX];
int cnt;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j) {       // 走到 i, j 位置
    if (i == ex && j == ey) {  // 走到终点
        cnt += 1;
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int ii = i + dir[k][0];
        int jj = j + dir[k][1];
        if (ii >= 1 && ii <= n && jj >= 1 && jj <= m && mz[ii][jj] == 0) {
            mz[ii][jj] = 1;  // 走过，设置为障碍物，不能走
            dfs(ii, jj);
            mz[ii][jj] = 0;  // 恢复
        }
    }
}

int main() {
    cin >> n >> m >> t >> sx >> sy >> ex >> ey;
    while (t--) {
        int x, y;
        cin >> x >> y;
        mz[x][y] = 1;
    }
    mz[sx][sy] = 1;  // 起点不能走
    dfs(sx, sy);     // 从起点开始走起
    cout << cnt;
    return 0;
}
