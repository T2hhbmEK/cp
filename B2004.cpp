// Problem: B2004 对齐输出
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B2004
// Memory Limit: 128 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int a;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 3; ++i) {
        cin >> a;
        cout << setw(8) << setfill(' ');
        cout << a << " \n"[i == 2];
    }
    return 0;
}