#include <bits/stdc++.h>
using namespace std;

int n, range;  // n 位密码，数字范围 0-range
int a[10];     // a[k] 表示第 k 位密码

void dfs(int k) {  // 枚举第 k 位密码
    if (k > n) {   // 1-n 位密码已经枚举完成
        for (int i = 1; i <= n; ++i) cout << a[i];
        cout << endl;
        return;
    }
    for (int i = 0; i <= range; ++i) {
        a[k] = i;
        dfs(k + 1);
        // a[k] = 0; // 无需回溯
    }
}

int main() {
    cin >> n >> range;
    dfs(1);
    return 0;
}
