#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7 + 10;
const int MOD = 114514;

int a[MAXN];

int main() {
    int n;
    cin >> n;
    a[1] = 0, a[2] = 1;
    for (int i = 3; i <= n; i++) {
        if (i % 2 != 0) {
            a[i] = (a[i - 1] + a[i - 2]) % MOD;
        } else {
            a[i] = (a[i - 1] - a[i - 2] + MOD) % MOD;
        }
    }
    cout << a[n];
    return 0;
}
