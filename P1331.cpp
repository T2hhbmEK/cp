#include <bits/stdc++.h>
using namespace std;
#define N 1005
int R, C, sea[N][N], cnt;
char tmp[N];
int di[4] = {0, 0, -1, 1};
int dj[4] = {-1, 1, 0, 0};
void _print(int m[N][N]) {
    for (int i = 0; i <= R + 1; ++i) {
        for (int j = 0; j <= C + 1; ++j) {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
}
void dfs(int i, int j) {
    if (sea[i][j] != -1) {
        return;
    }
    sea[i][j] = cnt;
    for (int k = 0; k < 4; ++k) {
        int i1 = i + di[k];
        int j1 = j + dj[k];
        dfs(i1, j1);
    }
}
bool _valid() {
    for (int i = 1; i < R; ++i) {
        for (int j = 1; j < C; ++j) {
            int s = sea[i][j];
            s += sea[i + 1][j];
            s += sea[i][j + 1];
            s += sea[i + 1][j + 1];
            if (s == -3) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; ++i) {
        scanf("%s", tmp + 1);
        for (int j = 1; j <= C; ++j) {
            if (tmp[j] == '#') {
                sea[i][j] = -1;
            }
        }
    }
    if (!_valid()) {
        printf("Bad placement.\n");
        return 0;
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (sea[i][j] == -1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    // _print(sea);
    printf("There are %d ships.\n", cnt);
    return 0;
}