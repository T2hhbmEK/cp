// 陈斌
#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, ex, ey, sum, minn = 0x3f3f;
string s[450];
int fx[] = {-1, 1, 0, 0};
int fy[] = {0, 0, -1, 1};

struct node {
    int x, y, step, sum;
};

void bfs(int x, int y) {
    queue<node> q;
    node t;
    t.x = x;
    t.y = y;
    t.step = 1;
    t.sum = 100;
    q.push(t);

    while (!q.empty()) {
        node tt = q.front();
        if (tt.x == ex && tt.y == ey) {
            if (tt.sum == 1800) {
                cout << tt.sum;
                return;
            }
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = tt.x + fx[i];
            int ny = tt.y + fy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && s[nx][ny] != '#') {
                node c;
                c.x = nx;
                c.y = ny;
                c.step = tt.step + 1;
                if (s[nx][ny] == '.' || s[nx][ny] == 'J') {
                    c.sum = tt.sum + 100;
                } else if (s[nx][ny] != '.' && s[nx][ny] != 'J' &&
                           s[nx][ny] >= '0' && s[nx][ny] <= '9') {
                    c.sum = tt.sum + ((s[nx][ny] - '0') * 1000);
                }

                q.push(c);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'T') {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'J') {
                ex = i;
                ey = j;
            }
        }
    }
    bfs(sx, sy);
    cout << minn;
    return 0;
}
