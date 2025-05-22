#include <bits/stdc++.h>
using namespace std;
// int a[1005][105];
int a[10009][10009];
void shifei(int i, int j) {
    a[i - 2][j] = 1;
    for (int k = -1; k <= 1; ++k) {
        a[i - 1][j + k] = 1;
    }
    for (int k = -2; k <= 2; ++k) {
        a[i][j + k] = 1;
    }
    for (int k = -1; k <= 1; ++k) {
        a[i + 1][j + k] = 1;
    }
    a[i + 2][j] = 1;
}
int main() {
    int n, m;
    cin >> n;
    // ooxoo
    // oxxxo
    // xxxxx
    // oxxxo
    // ooxoo
    cin >> m;
    int di = 3, dj = 3;
    while (m--) {
        int i, j;
        cin >> i >> j;
        shifei(i + di, j + dj);
    }
    int tj = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int i1 = i + di;
            int j1 = j + dj;
            tj += a[i1][j1];
        }
    }
    cout << tj;
    return 0;
}
