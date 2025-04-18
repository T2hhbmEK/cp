#include <bits/stdc++.h>
using namespace std;
#define N 1005
int n, m, mat[N][N], ans, kong[N][N];
int di[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void _print(int mat[N][N]) {
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= m + 1; ++j) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }
}

void dfs(int i, int j) {
    if (mat[i][j] == 0 && kong[i][j] == 0) {
        kong[i][j] = ans;
    } else {
        return;
    }
    for (int k = 0; k < 8; k++) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        dfs(i1, j1);
    }
}

int main() {
    // scanf("%d%d", &n, &m);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            scanf("%d", &x);
            if (x == 1) {
                mat[i][j] = -1;
            } else {
                mat[i][j] = x;
            }
        }
    }
    for (int i = 0; i <= n + 1; ++i) {
        mat[i][0] = -2;
        mat[i][m + 1] = -2;
        kong[i][0] = -2;
        kong[i][m + 1] = -2;
    }
    for (int j = 1; j <= m; ++j) {
        mat[0][j] = -2;
        mat[n + 1][j] = -2;
        kong[0][j] = -2;
        kong[n + 1][j] = -2;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = mat[i][j];
            if (x == 0) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int y = mat[i + di[k]][j + dj[k]];
                    if (y == -1) {
                        cnt++;
                    }
                }
                mat[i][j] = cnt;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = mat[i][j];
            int y = kong[i][j];
            if (x == 0 && y == 0) {
                ans++;
                dfs(i, j);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x = mat[i][j];
            if (x > 0) {
                bool flag = true;
                for (int k = 0; k < 8; ++k) {
                    int y = mat[i + di[k]][j + dj[k]];
                    if (y == 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    ans++;
                }
            }
        }
    }
    // _print(mat);
    // cout << endl;
    // _print(kong);
    cout << ans << endl;
    return 0;
}