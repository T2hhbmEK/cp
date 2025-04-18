#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define M 100005
int n, m, maze[N][N], ans[N][N], qi[M], qj[M];
char tmp[N];
void _print(int m[N][N]) {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
int dfs1(int i, int j) {
    if (ans[i][j] != 0) {
        return 0;
    }
    ans[i][j] = -1;
    int s = 1;
    for (int k = 0; k < 4; ++k) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (maze[i1][j1] + maze[i][j] == 3) {
            s += dfs1(i1, j1);
        }
    }
    return s;
}
void dfs2(int i, int j, int s) {
    if (ans[i][j] != -1) {
        return;
    }
    ans[i][j] = s;
    for (int k = 0; k < 4; ++k) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        if (ans[i1][j1] == -1) {
            dfs2(i1, j1, s);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        scanf("%s", tmp + 1);
        for (int j = 1; j <= n; ++j) {
            if (tmp[j] == '1') {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 2;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &qi[i], &qj[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (ans[i][j] == 0) {
                int cnt = dfs1(i, j);
                dfs2(i, j, cnt);
            }
        }
    }
    for (int k = 1; k <= m; ++k) {
        int i1 = qi[k];
        int j1 = qj[k];
        printf("%d\n", ans[i1][j1]);
    }
    // _print(ans);
    return 0;
}