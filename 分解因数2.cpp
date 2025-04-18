#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int n, a[N] = {2};        // a[0] = 2 方便枚举
void dfs(int k, int n) {  // k 表示当前是第几个因数，n 表示当前的 n
    if (n == 1) {         // n == 1 时输出
        for (int i = 1; i < k; ++i) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = a[k - 1]; i <= n; ++i) {  // 从上一个因数开始枚举
        if (n % i == 0) {                  // 如果 i 是 n 的因数
            a[k] = i;                      // 记录因数
            dfs(k + 1, n / i);             // 选下一个因数，更新 n
            // n 没有被修改，不需要回溯
        }
    }
}
int main() {
    cin >> n;
    dfs(1, n);
    return 0;
}
