#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e4 + 5;
int n;
int sx, sy;            // 起点坐标
int ex, ey;            // 终点坐标
bool vis[NMAX][NMAX];  // 标记是否访问过
int dis[NMAX][NMAX];   // 记录到达每个点的步数
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  // 上右下左

queue<int> qx;  // x坐标队列
queue<int> qy;  // y坐标队列

void bfs() {
    qx.push(sx);  // 将起点坐标入队
    qy.push(sy);
    vis[sx][sy] = 1;  // 标记起点已访问

    while (!qx.empty()) {    // 当队列不为空时
        int x = qx.front();  // 取出队首元素
        int y = qy.front();
        qx.pop();  // 弹出队首元素
        qy.pop();

        if (x == ex && y == ey) {  // 到达终点
            cout << dis[x][y] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {  // 遍历四个方向
            int xx = x + dir[i][0];    // 计算下一个点的坐标
            int yy = y + dir[i][1];
            if (xx >= 1 && xx <= n &&  // 判断 x 坐标是否合法
                yy >= 1 && yy <= n &&  // 判断 y 坐标是否合法
                vis[xx][yy] == 0) {    // 判断下一个点是否已访问
                vis[xx][yy] = 1;       // 标记下一个点已访问
                dis[xx][yy] = dis[x][y] + 1;  // 记录到达下一个点的步数
                qx.push(xx);                  // 将下一个点坐标入队
                qy.push(yy);
            }
        }
    }
}
int main() {
    cin >> n >> sx >> sy >> ex >> ey;  // 输入
    bfs();
    return 0;
}
