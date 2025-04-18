// Problem: P1003 [NOIP2011 提高组] 铺地毯
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1003
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int a[N][10];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> a[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i][1] <= x && x <= a[i][1] + a[i][3] && a[i][2] <= y &&
            y <= a[i][2] + a[i][4]) {
            ans = i;
        }
    }
    cout << ans;
    return 0;
}