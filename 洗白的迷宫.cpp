#include <bits/stdc++.h>
using namespace std;
const int NMAX = 55;  // 迷宫大小不一样
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
            // 因为走过的不用在走了，所以不需要恢复
            // mz[ii][jj] = 0;
        }
    }
}

int main() {
    cin >> n;
    // 输入不一样
    m = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                mz[i][j] = 1;
            } else if (c == '@') {
                sx = i;
                sy = j;
            } else if (c == 'E') {
                ex = i;
                ey = j;
            }
        }
    }
    mz[sx][sy] = 1;  // 起点不能走
    dfs(sx, sy);     // 从起点开始走起
    // 输出不一样
    if (cnt > 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
