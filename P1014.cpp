// Problem: P1014 [NOIP1999 普及组] Cantor 表
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1014
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int x = 1, y = 1;
    for (int i = 1, k = 1;; i++) {
        for (int j = 1; j <= i; j++, k++) {
            // cout << k << ' ' << x << ' ' << y << '\n';
            if (k == n) {
                cout << x << '/' << y;
                return 0;
            }
            if (i % 2 == 1) {
                if (x == 1) {
                    y++;
                } else {
                    y++, x--;
                }
            } else {
                if (y == 1) {
                    x++;
                } else {
                    x++, y--;
                }
            }
        }
    }
    return 0;
}