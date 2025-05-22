// Problem: U520705 B
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U520705?contestId=222025
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205;
int a[MAXN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= 2 * n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + 2 * n);
    for (int i = 1; i <= 2 * n; i += 2) {
        if (a[i + 1] - a[i] > d) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}