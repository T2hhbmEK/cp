#include <bits/stdc++.h>
using namespace std;
int n, cnt;
void dfs(int k) {
    if (k >= n) {           // 超过n级台阶
        if (k == n) cnt++;  // 正好到达n级台阶
        return;
    }
    dfs(k + 1);  // 一次走一级台阶
    dfs(k + 2);  // 一次走两级台阶
}

int main() {
    cin >> n;
    dfs(0);  // 从地板开始爬楼梯，所以从 0 开始
    cout << cnt;
    return 0;
}
