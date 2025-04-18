#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int combi(int n, int m) {
    int a = 1;
    for (int i = n; i > n - m; i--) {
        a *= i;
    }
    for (int i = 1; i <= m; i++) {
        a /= i;
    }
    return a;
}

int n, a[N][N];
int sum, ans;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void dfs(int i, int j, int cnt) {
    if (i == n && j == n) {
        if (cnt == 2) {
            ans = max(ans, sum);
        } else {
            a[n][n] = 0;
            dfs(1, 2, cnt + 1);
        }
        return;
    }
    for (int k = 0; k < 2; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (a[x][y] >= 0) {
            int t = a[x][y];
            a[x][y] = -1;
            sum += t;
            dfs(x, y, cnt);
            sum -= t;
            a[x][y] = t;
        }
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int i, j;
    do {
        cin >> i >> j >> a[i][j];
    } while (i && j);
    for (int i = 0; i <= n + 1; i++) {
        a[0][i] = a[n + 1][i] = -1;
        a[i][0] = a[i][n + 1] = -1;
    }
    if (n == 1) {
        cout << a[1][1] << endl;
        return 0;
    }
    dfs(2, 1, 1);
    cout << ans + a[1][1] + a[2][1] + a[1][2] << endl;
    return 0;
}
