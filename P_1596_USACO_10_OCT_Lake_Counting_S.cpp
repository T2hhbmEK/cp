#include <bits/stdc++.h>
#define maxn 110
using namespace std;

int n, m, ans;
char a[maxn][maxn];
int dr[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},  //
    {0, -1},  {0, 1},            //
    {1, -1},  {1, 0},  {1, 1},   //
};

void dfs(int i, int j) {
    a[i][j] = '.';
    for (int k = 0; k < 8; k++) {
        int ii = i + dr[k][0];
        int jj = j + dr[k][1];
        if (a[ii][jj] == 'W') {
            dfs(ii, jj);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] + 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
