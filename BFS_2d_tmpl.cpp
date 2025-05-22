#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
int mp[MAXN][MAXN];    // 地图 map
bool vis[MAXN][MAXN];  // 访问标记 visit
int n, m;              // 地图大小 n * m

void bfs() {
    queue<int> qx, qy;  // 广度优先搜索采用队列存储横纵坐标
    qx.push(起点行数);  // 起点坐标
    qy.push(起点列数);

    while (!qx.empty()) {
        int sx = qx.front();  // 取出队头
        int sy = qy.front();  // 取出队头
        qx.pop();             // 从队列中删除队头
        qy.pop();             // 从队列中删除队头

        if (找到答案) 处理并提前结束;  // 到达终点

        // 枚举相邻状态
        for (int i = 1; i <= 4; ++i) {  // 4 个方向，比如上右下左
            int next_x = ...;           // 计算相邻位置
            int next_y = ...;
            // 若该点复合要求（通常是判断是否在边界内），并且没被遍历过
            if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= m &&
                !vis[next_x][next_y]) {
                ...;                      // 根据题意做相应的操作
                vis[next_x][next_y] = 1;  // 打上访问标记
                qx.push(next_x);          // 同时将该点加入队列
                qy.push(next_y);
            }
        }
    }
}
