#include <bits/stdc++.h>
using namespace std;
#define N 35
int n, m[N][N];
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
void _print(int m[N][N]) {
    for (int i = 0; i <= n + 3; ++i) {
        for (int j = 0; j <= n + 3; ++j) {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
}
void _output(int m[N][N]) {
    for (int i = 2; i <= n + 1; ++i) {
        for (int j = 2; j <= n + 1; ++j) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}
void dfs(int i, int j) {
    if (m[i][j] != 0) {
        return;
    }
    m[i][j] = 3;
    for (int k = 0; k < 4; k++) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        dfs(i1, j1);
    }
}
int main() {
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) {
        for (int j = 2; j <= n + 1; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i <= n + 3; ++i) {
        m[i][0] = 1;
        m[i][n + 3] = 1;
        m[0][i] = 1;
        m[n + 3][i] = 1;
    }
    dfs(1, 1);
    for (int i = 2; i <= n + 1; ++i) {
        for (int j = 2; j <= n + 1; ++j) {
            if (m[i][j] == 3) {
                m[i][j] = 0;
            } else if (m[i][j] == 0) {
                m[i][j] = 2;
            }
        }
    }
    _output(m);
    return 0;
}