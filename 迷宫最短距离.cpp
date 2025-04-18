#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e3 + 7;
int n;
int m[NMAX][NMAX];  // 地图, 0 表示障碍物
struct Pos {
    int x, y, dis;
} s, e;                                              // 起点、终点
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};  // 上右下左
queue<Pos> q;

void bfs() {
    // 从起点开始搜索
    m[s.x][s.y] = 0;  // 标记起点为障碍物，避免重复访问
    s.dis = 0;
    q.push(s);

    while (!q.empty()) {
        Pos cur = q.front();  // 取出队首元素
        q.pop();

        if (cur.x == e.x && cur.y == e.y) {  // 到达终点
            cout << cur.dis;
            return;
        }

        for (int i = 0; i < 4; ++i) {
            Pos nxt;  // 计算下一个点的坐标
            nxt.x = cur.x + dir[i][0];
            nxt.y = cur.y + dir[i][1];
            nxt.dis = cur.dis + 1;
            if (m[nxt.x][nxt.y] != 0) {  // 判断下一个点是否合法
                m[nxt.x][nxt.y] = 0;  // 标记下一个点为障碍物，避免重复访问
                q.push(nxt);
            }
        }
    }

    cout << -1;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> m[i][j];
            if (m[i][j] == 6) {  // 起点
                s.x = i;
                s.y = j;
            } else if (m[i][j] == 8) {  // 终点
                e.x = i;
                e.y = j;
            }
        }
    }
    bfs();
    return 0;
}
