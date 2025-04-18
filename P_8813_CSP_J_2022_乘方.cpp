#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 1e9;

int qpow(int a, int b) {  // 快速幂
    int res = 1;
    while (b) {
        if (a > inf) return -1;
        if (b & 1) {
            res *= a;
            if (res > inf) return -1;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

signed main() {
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b) << endl;
    return 0;
}
