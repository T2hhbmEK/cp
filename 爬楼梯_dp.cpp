#include <bits/stdc++.h>
using namespace std;
long long f[105];  // f[i] 表示爬到第 i 级台阶的方法数

int main() {
    int n;
    cin >> n;
    f[1] = 1, f[2] = 2;  // 边界
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i - 1] + f[i - 2];  // 状态转移方程
    }
    cout << f[n];
    return 0;
}
