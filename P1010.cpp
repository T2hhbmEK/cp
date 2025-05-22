// Problem: P1010 [NOIP1998 普及组] 幂次方
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1010
// Memory Limit: 125 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

void f(int n) {
    vector<int> a;
    for (int i = 0; n; ++i) {
        if (n & 1) a.push_back(i);
        n >>= 1;
    }
    int len = a.size();
    for (int j = len - 1; j >= 0; --j) {
        int i = a[j];
        if (i == 0) {
            cout << "2(0)";
        } else if (i == 1) {
            cout << "2";
        } else {
            cout << "2(";
            f(i);
            cout << ")";
        }
        if (j > 0) cout << "+";
    }
}

int main() {
    int n;
    cin >> n;
    f(n);
    return 0;
}