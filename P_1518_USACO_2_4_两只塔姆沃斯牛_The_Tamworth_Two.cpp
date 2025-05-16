#include <bits/stdc++.h>
#define maxn 20
using namespace std;

int n = 10, fx, fy, fd, cx, cy, cd;
char a[maxn][maxn];
int dr[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1},
};

void mv(int &x, int &y, int &k) {
    int nx = x + dr[k][0];
    int ny = y + dr[k][1];
    if (a[nx][ny] == '.') {
        x = nx, y = ny;
    } else {
        k = (k + 1) % 4;
    }
}

int main() {
    for (int i = 1; i <= n; i++) {
        cin >> a[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'F') fx = i, fy = j, a[i][j] = '.';
            if (a[i][j] == 'C') cx = i, cy = j, a[i][j] = '.';
        }
    }
    for (int i = 1; i <= 160000; i++) {
        mv(fx, fy, fd);
        mv(cx, cy, cd);
        if (fx == cx && fy == cy) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
