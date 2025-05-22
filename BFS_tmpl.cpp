#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 7;
bool vis[MAXN];  // 访问标记 visit

void bfs() {
    queue<int> q;      // 广度优先搜索采用队列存储
    q.push(初始状态);  // 对迷宫问题，初始状态就是起点坐标

    while (!q.empty()) {
        int st = q.front();  // 取出队头
        q.pop();             // 从队列中删除队头

        if (找到答案) 处理并提前结束;  // 到达终点

        // 枚举相邻状态
        for (int i = 1; i <= 相邻状态数; ++i) {
            int x = ...;  // 计算相邻状态
            // 若该点复合要求（通常是判断是否在边界内），并且没被遍历过
            if (状态x合法 && !vis[x]) {
                ...;         // 根据题意做相应的操作
                vis[x] = 1;  // 打上访问标记
                q.push(x);   // 同时将该点加入队列
            }
        }
    }
}
