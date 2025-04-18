#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, cnt;
int a[N];               // 记录排列
bool vis[N];            // vis[i] 表示 i 是否被选过
bool is_prime(int x) {  // 判断 x 是否为素数
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return 0;
        }
    }
    return 1;
}
void dfs(int k) {
    if (k > n) {
        if (is_prime(a[n] + a[1])) {  // 判断首尾和是否为素数
            cnt += 1;
            for (int i = 1; i <= n; ++i) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= n; ++i) {
        // 如果 i 没有被选过，且和上一个数的和是素数，或者是第一个数
        if (!vis[i] && is_prime(a[k - 1] + i) || k == 1) {
            a[k] = i;    // 记录选择
            vis[i] = 1;  // 标记 i 已被选过
            dfs(k + 1);  // 选下一个
            vis[i] = 0;  // 回溯
        }
    }
}
int main() {
    cin >> n;
    dfs(1);
    if (cnt == 0) {
        cout << -1;
    }
    return 0;
}
