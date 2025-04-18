#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 7;
int x, y;
char ch;
int m[N][N];                // 地图
int dx[4] = {-1, 1, 0, 0};  // 上下左右
int dy[4] = {0, 0, -1, 1};  // 上下左右
int cnt;
void dfs(int i, int j) {
    if (m[i][j]) return;  // 如果是障碍物或者已经访问过，直接返回
    m[i][j] = 1;          // 标记为已访问
    for (int k = 0; k < 4; ++k) {
        dfs(i + dx[k], j + dy[k]);
    }
}
int main() {
    cin >> x >> y;
    // 初始化地图 外围一圈为障碍物
    // 中间一圈是洪水
    // 从 (2, 2) 开始输入地图
    for (int i = 0; i <= x + 3; ++i) {
        m[i][0] = 1;
        m[i][y + 3] = 1;
    }
    for (int j = 0; j <= y + 3; ++j) {
        m[0][j] = 1;
        m[x + 3][j] = 1;
    }
    for (int i = 2; i <= x + 1; ++i) {
        for (int j = 2; j <= y + 1; ++j) {
            cin >> ch;
            if (ch == '*') m[i][j] = 1;
        }
    }
    dfs(1, 1);
    for (int i = 2; i <= x + 1; ++i) {
        for (int j = 2; j <= y + 1; ++j) {
            if (m[i][j] == 0) cnt += 1;
        }
    }
    cout << cnt;
    return 0;
}
