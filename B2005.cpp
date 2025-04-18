// Problem: B2005 字符三角形
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B2005
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n = 3;
    char ch;
    cin >> ch;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            cout << ' ';
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << ch;
        }
        cout << '\n';
    }
    return 0;
}