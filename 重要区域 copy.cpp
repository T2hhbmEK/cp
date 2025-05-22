#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
int x, y;
char ch;
int m[N][N];
int dir[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};  // 上下左右
int cnt;
void dfs(int i, int j) {
    if (m[i][j]) return;  // 如果是障碍物或者已经访问过，直接返回
    m[i][j] = 1;          // 标记为已访问
    for (int k = 0; k < 4; ++k) {
        int ii = i + dir[k][0];
        int jj = j + dir[k][1];
        // 如果在地图内且不是障碍物
        if (ii >= 1 && ii <= x && jj >= 1 && jj <= y && m[ii][jj] == 0) {
            dfs(i + dir[k][0], j + dir[k][1]);
        }
    }
}
int main() {
    cin >> x >> y;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            cin >> ch;
            if (ch == '*') m[i][j] = 1;
        }
    }
    // 从边缘开始搜索
    for (int i = 1; i <= x; i++) {
        dfs(i, 1);  // 左边缘
        dfs(i, y);  // 右边缘
    }
    for (int j = 1; j <= y; j++) {
        dfs(1, j);  // 上边缘
        dfs(x, j);  // 下边缘
    }
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= y; ++j) {
            if (m[i][j] == 0) cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}
