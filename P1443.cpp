#include <bits/stdc++.h>
using namespace std;
#define N 405
int n, m, x, y, mat[N][N];
queue<int> qx;
queue<int> qy;
int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
void _fill(int x) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            mat[i][j] = x;
        }
    }
}
void _print() {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%-5d", mat[i][j]);
        }
        printf("\n");
    }
}
void _push(int x, int y) {
    qx.push(x);
    qy.push(y);
}
void _pop(int &x, int &y) {
    x = qx.front();
    y = qy.front();
    qx.pop();
    qy.pop();
}
int main() {
    // scanf("%d%d%d%d", &n, &m, &x, &y);
    scanf("%d%d%d%d", &m, &n, &y, &x);
    _fill(-1);
    mat[y][x] = 0;
    _push(x, y);
    while (qx.size() > 0) {
        int nx, ny;
        _pop(nx, ny);
        for (int i = 0; i < 8; ++i) {
            int x1 = nx + dx[i];
            int y1 = ny + dy[i];
            if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && mat[y1][x1] == -1) {
                mat[y1][x1] = mat[ny][nx] + 1;
                _push(x1, y1);
            }
        }
    }
    _print();
    return 0;
}