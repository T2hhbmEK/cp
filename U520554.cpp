// Problem: U520554 A
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U520554?contestId=222025
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0, j = 2; j < n; i++, j++) {
        bool ok = 1;
        for (int k = i; k <= j; k++) {
            if (s[k] != 'o') ok = 0;
        }
        if (ok) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}